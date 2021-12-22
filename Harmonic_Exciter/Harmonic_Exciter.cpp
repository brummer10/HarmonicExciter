
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <cstring>
#include <unistd.h>

#include <lv2.h>
#include "harmonic_exciter.cc"
///////////////////////// MACRO SUPPORT ////////////////////////////////

#define PLUGIN_URI "https://github.com/brummer10/HarmonicExciter"

#ifndef max
#define max(x, y) (((x) > (y)) ? (x) : (y))
#endif
#ifndef min
#define min(x, y) (((x) < (y)) ? (x) : (y))
#endif


////////////////////////////// PLUG-IN CLASS ///////////////////////////

namespace harmonic_exciter {

class Xharmonic_exciter
{
private:
    harmonic_exciter::Dsp* dsp;
    float* input0;
    float* output0;
    float* bypass;
    float bypass_;
    float* amp;
    float amp_;
    float* bpf;
    float bpf_;
    float* direct;
    float direct_;
    float* harmonics;
    float harmonics_;
    // bypass ramping
    bool needs_ramp_down;
    bool needs_ramp_up;
    float ramp_down;
    float ramp_up;
    float ramp_up_step;
    float ramp_down_step;
    bool bypassed;

    // private functions
    inline void run_dsp_(uint32_t n_samples);
    inline void connect_(uint32_t port,void* data);
    inline void init_dsp_(uint32_t rate);
    inline void connect_all__ports(uint32_t port, void* data);
    inline void activate_f();
    inline void clean_up();
    inline void deactivate_f();
public:
    // LV2 Descriptor
    static const LV2_Descriptor descriptor;
    // static wrapper to private functions
    static void deactivate(LV2_Handle instance);
    static void cleanup(LV2_Handle instance);
    static void run(LV2_Handle instance, uint32_t n_samples);
    static void activate(LV2_Handle instance);
    static void connect_port(LV2_Handle instance, uint32_t port, void* data);
    static LV2_Handle instantiate(const LV2_Descriptor* descriptor,
                                double rate, const char* bundle_path,
                                const LV2_Feature* const* features);
    Xharmonic_exciter();
    ~Xharmonic_exciter();
};

// constructor
Xharmonic_exciter::Xharmonic_exciter() :
    dsp(harmonic_exciter::plugin()),
    input0(NULL),
    output0(NULL),
    bypass(NULL),
    bypass_(2),
    amp(NULL),
    bpf(NULL),
    direct(NULL),
    harmonics(NULL),
    needs_ramp_down(false),
    needs_ramp_up(false),
    bypassed(false) {};

// destructor
Xharmonic_exciter::~Xharmonic_exciter() { };

///////////////////////// PRIVATE CLASS  FUNCTIONS /////////////////////

void Xharmonic_exciter::init_dsp_(uint32_t rate)
{
    dsp->init(rate);
    // set values for internal ramping
    ramp_down_step = 32 * (256 * rate) / 48000; 
    ramp_up_step = ramp_down_step;
    ramp_down = ramp_down_step;
    ramp_up = 0.0;
}

// connect the Ports used by the plug-in class
void Xharmonic_exciter::connect_(uint32_t port,void* data)
{
    switch ((PortIndex)port)
    {
        case 0:
            input0 = static_cast<float*>(data);
            break;
        case 1:
            output0 = static_cast<float*>(data);
            break;
        case 2:
            bypass = static_cast<float*>(data);
            break;
        case 3:
            amp = static_cast<float*>(data);
            break;
        case 4:
            bpf = static_cast<float*>(data);
            break;
        case 5:
            direct = static_cast<float*>(data);
            break;
        case 6:
            harmonics = static_cast<float*>(data);
            break;
        default:
            break;
    }
}

void Xharmonic_exciter::activate_f()
{
    // allocate the internal DSP mem
}

void Xharmonic_exciter::clean_up()
{
    // delete the internal DSP mem
}

void Xharmonic_exciter::deactivate_f()
{
    // delete the internal DSP mem
}

void Xharmonic_exciter::run_dsp_(uint32_t n_samples)
{
    if(n_samples<1) return;

    // get controller values
#define  amp_ (*(amp))
#define  bpf_ (*(bpf))
#define  direct_ (*(direct))
#define  harmonics_ (*(harmonics))

    // do inplace processing on default
    if(output0 != input0)
        memcpy(output0, input0, n_samples*sizeof(float));

    float buf0[n_samples];
    // check if bypass is pressed
    if (bypass_ != static_cast<uint32_t>(*(bypass))) {
        bypass_ = static_cast<uint32_t>(*(bypass));
        if (!bypass_) {
            needs_ramp_down = true;
            needs_ramp_up = false;
        } else {
            needs_ramp_down = false;
            needs_ramp_up = true;
            bypassed = false;
        }
    }

    if (needs_ramp_down || needs_ramp_up) {
         memcpy(buf0, input0, n_samples*sizeof(float));
    }
    if (!bypassed) {
        dsp->compute(n_samples, output0, output0);
    }
    // check if ramping is needed
    if (needs_ramp_down) {
        float fade = 0;
        for (uint32_t i=0; i<n_samples; i++) {
            if (ramp_down >= 0.0) {
                --ramp_down; 
            }
            fade = max(0.0,ramp_down) /ramp_down_step ;
            output0[i] = output0[i] * fade + buf0[i] * (1.0 - fade);
        }
        if (ramp_down <= 0.0) {
            // when ramped down, clear buffer from dsp
            needs_ramp_down = false;
            bypassed = true;
            ramp_down = ramp_down_step;
            ramp_up = 0.0;
        } else {
            ramp_up = ramp_down;
        }
    } else if (needs_ramp_up) {
        float fade = 0;
        for (uint32_t i=0; i<n_samples; i++) {
            if (ramp_up < ramp_up_step) {
                ++ramp_up ;
            }
            fade = min(ramp_up_step,ramp_up) /ramp_up_step ;
            output0[i] = output0[i] * fade + buf0[i] * (1.0 - fade);
        }
        if (ramp_up >= ramp_up_step) {
            needs_ramp_up = false;
            ramp_up = 0.0;
            ramp_down = ramp_down_step;
        } else {
            ramp_down = ramp_up;
        }
    }
#undef  amp_
#undef  bpf_
#undef  direct_
#undef  harmonics_
}

void Xharmonic_exciter::connect_all__ports(uint32_t port, void* data)
{
    // connect the Ports used by the plug-in class
    connect_(port,data);
    dsp->connect(port,data);
}

////////////////////// STATIC CLASS  FUNCTIONS  ////////////////////////

LV2_Handle 
Xharmonic_exciter::instantiate(const LV2_Descriptor* descriptor,
                            double rate, const char* bundle_path,
                            const LV2_Feature* const* features)
{
    // init the plug-in class
    Xharmonic_exciter *self = new Xharmonic_exciter();
    if (!self) {
        return NULL;
    }
    self->init_dsp_((uint32_t)rate);
    return (LV2_Handle)self;
}

void Xharmonic_exciter::connect_port(LV2_Handle instance, 
                                   uint32_t port, void* data)
{
    // connect all ports
    static_cast<Xharmonic_exciter*>(instance)->connect_all__ports(port, data);
}

void Xharmonic_exciter::activate(LV2_Handle instance)
{
    // allocate needed mem
    static_cast<Xharmonic_exciter*>(instance)->activate_f();
}

void Xharmonic_exciter::run(LV2_Handle instance, uint32_t n_samples)
{
    // run dsp
    static_cast<Xharmonic_exciter*>(instance)->run_dsp_(n_samples);
}

void Xharmonic_exciter::deactivate(LV2_Handle instance)
{
    // free allocated mem
    static_cast<Xharmonic_exciter*>(instance)->deactivate_f();
}

void Xharmonic_exciter::cleanup(LV2_Handle instance)
{
    // well, clean up after us
    Xharmonic_exciter* self = static_cast<Xharmonic_exciter*>(instance);
    self->clean_up();
    delete self;
}

const LV2_Descriptor Xharmonic_exciter::descriptor =
{
    PLUGIN_URI ,
    Xharmonic_exciter::instantiate,
    Xharmonic_exciter::connect_port,
    Xharmonic_exciter::activate,
    Xharmonic_exciter::run,
    Xharmonic_exciter::deactivate,
    Xharmonic_exciter::cleanup,
    NULL
};

} // end namespace harmonic_exciter

////////////////////////// LV2 SYMBOL EXPORT ///////////////////////////

LV2_SYMBOL_EXPORT
const LV2_Descriptor*
lv2_descriptor(uint32_t index)
{
    switch (index)
    {
        case 0:
            return &harmonic_exciter::Xharmonic_exciter::descriptor;
        default:
            return NULL;
    }
}

///////////////////////////// FIN //////////////////////////////////////
