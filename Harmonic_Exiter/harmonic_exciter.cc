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
	float fConst0;
	float fConst2;
	FAUSTFLOAT fVslider0;
	FAUSTFLOAT	*fVslider0_;
	float fRec1[2];
	float fConst4;
	FAUSTFLOAT fVslider1;
	FAUSTFLOAT	*fVslider1_;
	float fRec3[2];
	float fConst5;
	float fConst6;
	float fRec2[2];
	float fConst9;
	float fConst10;
	FAUSTFLOAT fVslider2;
	FAUSTFLOAT	*fVslider2_;
	float fRec6[2];
	float fConst12;
	float fConst14;
	float fConst15;
	float fConst16;
	float fConst17;
	float fRec5[3];
	float fConst19;
	float fConst21;
	float fConst22;
	float fConst23;
	float fConst24;
	float fRec4[2];
	FAUSTFLOAT fVslider3;
	FAUSTFLOAT	*fVslider3_;
	float fRec7[2];
	float fVec0[2];
	float fConst25;
	float fRec0[2];


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
	for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) fRec1[l0] = 0.0f;
	for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) fRec3[l1] = 0.0f;
	for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) fRec2[l2] = 0.0f;
	for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) fRec6[l3] = 0.0f;
	for (int l4 = 0; (l4 < 3); l4 = (l4 + 1)) fRec5[l4] = 0.0f;
	for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) fRec4[l5] = 0.0f;
	for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) fRec7[l6] = 0.0f;
	for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) fVec0[l7] = 0.0f;
	for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) fRec0[l8] = 0.0f;
}

inline void Dsp::init(uint32_t sample_rate)
{
	fSampleRate = sample_rate;
	fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
	float fConst1 = (3.14159274f / fConst0);
	fConst2 = (1.0f / (fConst1 + 1.0f));
	float fConst3 = (4.42226389e-09f * fConst0);
	fConst4 = (3.36313397e-23f - fConst3);
	fConst5 = (2.07850571e-05f * fConst0);
	fConst6 = (fConst3 + 3.36313397e-23f);
	float fConst7 = (2.07413941e-05f * fConst0);
	float fConst8 = (fConst7 + 0.00441306271f);
	fConst9 = (fConst0 / fConst8);
	fConst10 = mydsp_faustpower2_f(fConst0);
	float fConst11 = (1.3380459e-09f * fConst0);
	fConst12 = (fConst11 + -5.57205567e-07f);
	float fConst13 = (2.32703634e-09f * fConst0);
	fConst14 = (4.84526595e-07f - fConst13);
	fConst15 = (1.0117549e-09f * fConst0);
	fConst16 = (fConst11 + 5.57205567e-07f);
	fConst17 = (-4.84526595e-07f - fConst13);
	float fConst18 = (7.43339834e-10f * fConst0);
	fConst19 = (-1.47050536e-12f - fConst18);
	float fConst20 = (1.2927649e-09f * fConst0);
	fConst21 = (fConst20 + 1.27870034e-12f);
	fConst22 = (1.47050536e-12f - fConst18);
	fConst23 = (fConst20 + -1.27870034e-12f);
	fConst24 = ((0.00441306271f - fConst7) / fConst8);
	fConst25 = (1.0f - fConst1);
	clear_state_f();
}

void always_inline Dsp::compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0)
{
#define fVslider0 (*fVslider0_)
#define fVslider1 (*fVslider1_)
#define fVslider2 (*fVslider2_)
#define fVslider3 (*fVslider3_)
	float fSlow0 = (0.00700000022f * float(fVslider0));
	float fSlow1 = (0.000366769877f * (std::exp((3.0f * float(fVslider1))) + -1.0f));
	float fSlow2 = (0.00700000022f * float(fVslider2));
	float fSlow3 = (0.000366769877f * (std::exp((3.0f * float(fVslider3))) + -1.0f));
	for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
		fRec1[0] = (fSlow0 + (0.992999971f * fRec1[1]));
		fRec3[0] = (fSlow1 + (0.992999971f * fRec3[1]));
		float fTemp0 = (fConst5 + ((fConst6 * fRec3[0]) + 0.00221115421f));
		fRec2[0] = (float(input0[i0]) - ((fRec2[1] * (((fConst4 * fRec3[0]) + 0.00221115421f) - fConst5)) / fTemp0));
		float fTemp1 = (0.000442226388f * fRec3[0]);
		float fTemp2 = ((fRec2[0] * ((0.0f - fTemp1) + -2.07846406e-05f)) + (fRec2[1] * (fTemp1 + 2.07846406e-05f)));
		fRec6[0] = (fSlow2 + (0.992999971f * fRec6[1]));
		float fTemp3 = (fConst15 * fRec6[0]);
		float fTemp4 = ((fConst0 * (fConst16 + (fRec6[0] * (fConst17 + fTemp3)))) + 5.22587875e-08f);
		fRec5[0] = ((fConst0 * (fTemp2 / fTemp0)) - (((fRec5[1] * ((fConst10 * ((fRec6[0] * ((0.0f - (2.0235098e-09f * fRec6[0])) + 4.65407268e-09f)) + -2.67609179e-09f)) + 1.04517575e-07f)) + (fRec5[2] * ((fConst0 * (fConst12 + (fRec6[0] * (fConst14 + fTemp3)))) + 5.22587875e-08f))) / fTemp4));
		float fTemp5 = (fConst0 * (0.0f - (5.62071722e-10f * fRec6[0])));
		fRec4[0] = (((((fRec5[0] * ((fConst0 * (fConst19 + (fRec6[0] * (fConst21 + fTemp5)))) + -2.90320481e-18f)) + (fRec5[1] * ((fConst10 * ((fRec6[0] * ((1.12414344e-09f * fRec6[0]) + -2.58552979e-09f)) + 1.48667967e-09f)) + -5.80640961e-18f))) + (fRec5[2] * ((fConst0 * (fConst22 + (fRec6[0] * (fConst23 + fTemp5)))) + -2.90320481e-18f))) / fTemp4) - (fConst24 * fRec4[1]));
		fRec7[0] = (fSlow3 + (0.992999971f * fRec7[1]));
		float fTemp6 = (fConst9 * ((fRec4[0] * (0.0f - (9.65139043e-05f * fRec7[0]))) + (9.65139043e-05f * (fRec7[0] * fRec4[1]))));
		float fElse0 = float(harmonic_exciterclip(float(fTemp6)));
		float fTemp7 = ((fConst0 * ((fRec1[0] * fTemp2) / fTemp0)) + (int(signbit(float(fTemp6))) ? fElse0 : fTemp6));
		fVec0[0] = fTemp7;
		fRec0[0] = (fConst2 * ((fTemp7 - fVec0[1]) + (fConst25 * fRec0[1])));
		output0[i0] = FAUSTFLOAT(fRec0[0]);
		fRec1[1] = fRec1[0];
		fRec3[1] = fRec3[0];
		fRec2[1] = fRec2[0];
		fRec6[1] = fRec6[0];
		fRec5[2] = fRec5[1];
		fRec5[1] = fRec5[0];
		fRec4[1] = fRec4[0];
		fRec7[1] = fRec7[0];
		fVec0[1] = fVec0[0];
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
		fVslider1_ = static_cast<float*>(data); // , 0.5f, 0.0f, 1.0f, 0.00999999978f 
		break;
	case BPF: 
		fVslider2_ = static_cast<float*>(data); // , 0.5f, 0.0f, 1.0f, 0.00999999978f 
		break;
	case DIRECT: 
		fVslider0_ = static_cast<float*>(data); // , 0.5f, 0.0f, 1.0f, 0.00999999978f 
		break;
	case HARMONICS: 
		fVslider3_ = static_cast<float*>(data); // , 0.5f, 0.0f, 1.0f, 0.00999999978f 
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
