// generated from file 'harmonic_exciter.dsp' by dsp2cc:
// Code generated with Faust 2.37.3 (https://faust.grame.fr)

#include <cmath>
#include <algorithm>

#define FAUSTFLOAT float

using std::signbit;

#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))

template<class T> inline T mydsp_faustpower2_f(T x) {return (x * x);}
template<class T> inline T mydsp_faustpower3_f(T x) {return ((x * x) * x);}
template<class T> inline T mydsp_faustpower4_f(T x) {return (((x * x) * x) * x);}
template<class T> inline T mydsp_faustpower5_f(T x) {return ((((x * x) * x) * x) * x);}
template<class T> inline T mydsp_faustpower6_f(T x) {return (((((x * x) * x) * x) * x) * x);}

#define always_inline inline __attribute__((__always_inline__))

typedef enum
{
   input0,
   output0,
   bypass,
   AMP, 
   BPF, 
   DIRECT, 
   HARMONICS, 
} PortIndex;

#include "harmonic_exciter_table.h"
#include "math.h"

namespace harmonic_exciter {

class Dsp {
private:
	uint32_t fSampleRate;
	double fConst0;
	double fConst2;
	double fConst4;
	double fConst5;
	double fConst6;
	double fConst7;
	double fConst9;
	FAUSTFLOAT fVslider0;
	FAUSTFLOAT	*fVslider0_;
	double fRec3[2];
	double fConst10;
	double fVec0[2];
	double fConst11;
	double fRec2[3];
	FAUSTFLOAT fVslider1;
	FAUSTFLOAT	*fVslider1_;
	double fRec4[2];
	double fConst13;
	double fConst14;
	double fConst15;
	FAUSTFLOAT fVslider2;
	FAUSTFLOAT	*fVslider2_;
	double fRec7[2];
	double fConst17;
	double fConst19;
	double fConst20;
	double fConst22;
	double fConst24;
	double fConst25;
	double fConst26;
	double fConst27;
	double fConst28;
	double fRec6[3];
	FAUSTFLOAT fVslider3;
	FAUSTFLOAT	*fVslider3_;
	double fRec8[2];
	double fRec5[2];
	double fVec1[2];
	double fRec1[2];
	double fConst29;
	double fRec0[2];


public:
	void connect(uint32_t port,void* data);
	void del_instance(Dsp *p);
	void clear_state_f();
	void init(uint32_t sample_rate);
	void compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0);
	Dsp();
	~Dsp();
};



Dsp::Dsp() {
}

Dsp::~Dsp() {
}

inline void Dsp::clear_state_f()
{
	for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) fRec3[l0] = 0.0;
	for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) fVec0[l1] = 0.0;
	for (int l2 = 0; (l2 < 3); l2 = (l2 + 1)) fRec2[l2] = 0.0;
	for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) fRec4[l3] = 0.0;
	for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) fRec7[l4] = 0.0;
	for (int l5 = 0; (l5 < 3); l5 = (l5 + 1)) fRec6[l5] = 0.0;
	for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) fRec8[l6] = 0.0;
	for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) fRec5[l7] = 0.0;
	for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) fVec1[l8] = 0.0;
	for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) fRec1[l9] = 0.0;
	for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) fRec0[l10] = 0.0;
}

inline void Dsp::init(uint32_t sample_rate)
{
	fSampleRate = sample_rate;
	fConst0 = std::min<double>(192000.0, std::max<double>(1.0, double(fSampleRate)));
	double fConst1 = (3.1415926535897931 / fConst0);
	fConst2 = (1.0 / (fConst1 + 1.0));
	double fConst3 = (2.0833116321705e-05 * fConst0);
	fConst4 = (1.0 / (fConst3 + 1.04165581608525e-05));
	fConst5 = (1.04165581608525e-05 - fConst3);
	fConst6 = (2.0832699667711599e-05 * fConst0);
	fConst7 = (0.0 - fConst6);
	double fConst8 = (4.4222639995467799e-09 * fConst0);
	fConst9 = (3.3631338888506301e-23 - fConst8);
	fConst10 = (2.0785056490685802e-05 * fConst0);
	fConst11 = (fConst8 + 3.3631338888506301e-23);
	double fConst12 = (2.0741394527802301e-05 * fConst0);
	fConst13 = (1.0 / (fConst12 + 0.0044130626654898496));
	fConst14 = (0.0044130626654898496 - fConst12);
	fConst15 = mydsp_faustpower2_f(fConst0);
	double fConst16 = (1.34037627712556e-09 * fConst0);
	fConst17 = (fConst16 + -4.9398125870817105e-07);
	double fConst18 = (2.3310891776096599e-09 * fConst0);
	fConst19 = (4.2954892061580098e-07 - fConst18);
	fConst20 = (1.01351703374333e-09 * fConst0);
	double fConst21 = (7.44634457744722e-10 * fConst0);
	fConst22 = (1.4730664792215101e-12 - fConst21);
	double fConst23 = (1.2950164482516899e-09 * fConst0);
	fConst24 = (fConst23 + -1.28092737323609e-12);
	fConst25 = (-1.4730664792215101e-12 - fConst21);
	fConst26 = (fConst23 + 1.28092737323609e-12);
	fConst27 = (fConst16 + 4.9398125870817105e-07);
	fConst28 = (-4.2954892061580098e-07 - fConst18);
	fConst29 = (1.0 - fConst1);
	clear_state_f();
}

void always_inline Dsp::compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0)
{
#define fVslider0 (*fVslider0_)
#define fVslider1 (*fVslider1_)
#define fVslider2 (*fVslider2_)
#define fVslider3 (*fVslider3_)
	double fSlow0 = (0.00036676987543879196 * (std::exp((3.0 * double(fVslider0))) + -1.0));
	double fSlow1 = (0.0070000000000000062 * double(fVslider1));
	double fSlow2 = (0.0070000000000000062 * double(fVslider2));
	double fSlow3 = (0.00036676987543879196 * (std::exp((3.0 * double(fVslider3))) + -1.0));
	for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
		fRec3[0] = (fSlow0 + (0.99299999999999999 * fRec3[1]));
		double fTemp0 = double(input0[i0]);
		fVec0[0] = fTemp0;
		double fTemp1 = (0.00044222639995467798 * fRec3[0]);
		fRec2[0] = (0.0 - (((fRec2[1] * (((fConst9 * fRec3[0]) + 0.00221115411109339) - fConst10)) - (fConst0 * ((fTemp0 * ((0.0 - fTemp1) + -2.07846407978698e-05)) + (fVec0[1] * (fTemp1 + 2.07846407978698e-05))))) / (fConst10 + ((fConst11 * fRec3[0]) + 0.00221115411109339))));
		fRec4[0] = (fSlow1 + (0.99299999999999999 * fRec4[1]));
		fRec7[0] = (fSlow2 + (0.99299999999999999 * fRec7[1]));
		double fTemp2 = (fConst20 * fRec7[0]);
		double fTemp3 = (fConst0 * (0.0 - (5.63050629674648e-10 * fRec7[0])));
		fRec6[0] = (0.0 - ((((fRec6[1] * ((fConst15 * ((fRec7[0] * ((0.0 - (2.02703406748666e-09 * fRec7[0])) + 4.6621783552193298e-09)) + -2.6807525542511102e-09)) + 1.04699355770573e-07)) + (fRec6[2] * ((fConst0 * (fConst17 + (fRec7[0] * (fConst19 + fTemp2)))) + 5.2349677885286598e-08))) - (((fRec2[2] * ((fConst0 * (fConst22 + (fRec7[0] * (fConst24 + fTemp3)))) + -2.9082612026393002e-18)) + (fRec2[1] * ((fConst15 * ((fRec7[0] * ((1.1261012593492999e-09 * fRec7[0]) + -2.5900328965033798e-09)) + 1.4892689154894401e-09)) + -5.8165224052785903e-18))) + (fRec2[0] * ((fConst0 * (fConst25 + (fRec7[0] * (fConst26 + fTemp3)))) + -2.9082612026393002e-18)))) / ((fConst0 * (fConst27 + (fRec7[0] * (fConst28 + fTemp2)))) + 5.2349677885286598e-08)));
		fRec8[0] = (fSlow3 + (0.99299999999999999 * fRec8[1]));
		fRec5[0] = (0.0 - (fConst13 * ((fConst14 * fRec5[1]) - (fConst0 * ((fRec6[0] * (0.0 - (9.6513901108518995e-05 * fRec8[0]))) + (9.6513901108518995e-05 * (fRec8[0] * fRec6[1])))))));
		double fElse0 = double(harmonic_exciterclip(double(fRec5[0])));
		double fTemp4 = ((fRec2[0] * fRec4[0]) + (int(signbit(double(fRec5[0]))) ? fElse0 : fRec5[0]));
		fVec1[0] = fTemp4;
		fRec1[0] = (0.0 - (fConst4 * ((fConst5 * fRec1[1]) - ((fConst7 * fTemp4) + (fConst6 * fVec1[1])))));
		fRec0[0] = (fConst2 * ((fRec1[0] - fRec1[1]) + (fConst29 * fRec0[1])));
		output0[i0] = FAUSTFLOAT(fRec0[0]);
		fRec3[1] = fRec3[0];
		fVec0[1] = fVec0[0];
		fRec2[2] = fRec2[1];
		fRec2[1] = fRec2[0];
		fRec4[1] = fRec4[0];
		fRec7[1] = fRec7[0];
		fRec6[2] = fRec6[1];
		fRec6[1] = fRec6[0];
		fRec8[1] = fRec8[0];
		fRec5[1] = fRec5[0];
		fVec1[1] = fVec1[0];
		fRec1[1] = fRec1[0];
		fRec0[1] = fRec0[0];
	}
#undef fVslider0
#undef fVslider1
#undef fVslider2
#undef fVslider3
}


void Dsp::connect(uint32_t port,void* data)
{
	switch ((PortIndex)port)
	{
	case AMP: 
		fVslider0_ = static_cast<float*>(data); // , 0.5, 0.0, 1.0, 0.01 
		break;
	case BPF: 
		fVslider2_ = static_cast<float*>(data); // , 0.5, 0.0, 1.0, 0.01 
		break;
	case DIRECT: 
		fVslider1_ = static_cast<float*>(data); // , 0.5, 0.0, 1.0, 0.01 
		break;
	case HARMONICS: 
		fVslider3_ = static_cast<float*>(data); // , 0.5, 0.0, 1.0, 0.01 
		break;
	default:
		break;
	}
}

Dsp *plugin() {
	return new Dsp();
}

void Dsp::del_instance(Dsp *p)
{
	delete p;
}
} // end namespace harmonic_exciter
