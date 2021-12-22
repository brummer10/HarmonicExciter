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
	float fConst4;
	float fConst5;
	float fConst6;
	float fConst7;
	float fConst9;
	FAUSTFLOAT fVslider0;
	FAUSTFLOAT	*fVslider0_;
	float fRec3[2];
	float fConst10;
	float fVec0[2];
	float fConst11;
	float fRec2[3];
	FAUSTFLOAT fVslider1;
	FAUSTFLOAT	*fVslider1_;
	float fRec4[2];
	float fConst13;
	float fConst14;
	float fConst15;
	FAUSTFLOAT fVslider2;
	FAUSTFLOAT	*fVslider2_;
	float fRec7[2];
	float fConst17;
	float fConst19;
	float fConst20;
	float fConst22;
	float fConst24;
	float fConst25;
	float fConst26;
	float fConst27;
	float fConst28;
	float fRec6[3];
	FAUSTFLOAT fVslider3;
	FAUSTFLOAT	*fVslider3_;
	float fRec8[2];
	float fRec5[2];
	float fVec1[2];
	float fRec1[2];
	float fConst29;
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
	for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) fRec3[l0] = 0.0f;
	for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) fVec0[l1] = 0.0f;
	for (int l2 = 0; (l2 < 3); l2 = (l2 + 1)) fRec2[l2] = 0.0f;
	for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) fRec4[l3] = 0.0f;
	for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) fRec7[l4] = 0.0f;
	for (int l5 = 0; (l5 < 3); l5 = (l5 + 1)) fRec6[l5] = 0.0f;
	for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) fRec8[l6] = 0.0f;
	for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) fRec5[l7] = 0.0f;
	for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) fVec1[l8] = 0.0f;
	for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) fRec1[l9] = 0.0f;
	for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) fRec0[l10] = 0.0f;
}

inline void Dsp::init(uint32_t sample_rate)
{
	fSampleRate = sample_rate;
	fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
	float fConst1 = (3.14159274f / fConst0);
	fConst2 = (1.0f / (fConst1 + 1.0f));
	float fConst3 = (2.08331167e-05f * fConst0);
	fConst4 = (1.0f / (fConst3 + 1.04165583e-05f));
	fConst5 = (1.04165583e-05f - fConst3);
	fConst6 = (2.08327001e-05f * fConst0);
	fConst7 = (0.0f - fConst6);
	float fConst8 = (4.42226389e-09f * fConst0);
	fConst9 = (3.36313397e-23f - fConst8);
	fConst10 = (2.07850571e-05f * fConst0);
	fConst11 = (fConst8 + 3.36313397e-23f);
	float fConst12 = (2.07413941e-05f * fConst0);
	fConst13 = (1.0f / (fConst12 + 0.00441306271f));
	fConst14 = (0.00441306271f - fConst12);
	fConst15 = mydsp_faustpower2_f(fConst0);
	float fConst16 = (1.34037625e-09f * fConst0);
	fConst17 = (fConst16 + -4.93981247e-07f);
	float fConst18 = (2.3310891e-09f * fConst0);
	fConst19 = (4.29548919e-07f - fConst18);
	fConst20 = (1.01351705e-09f * fConst0);
	float fConst21 = (7.44634465e-10f * fConst0);
	fConst22 = (1.47306646e-12f - fConst21);
	float fConst23 = (1.29501643e-09f * fConst0);
	fConst24 = (fConst23 + -1.2809274e-12f);
	fConst25 = (-1.47306646e-12f - fConst21);
	fConst26 = (fConst23 + 1.2809274e-12f);
	fConst27 = (fConst16 + 4.93981247e-07f);
	fConst28 = (-4.29548919e-07f - fConst18);
	fConst29 = (1.0f - fConst1);
	clear_state_f();
}

void always_inline Dsp::compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0)
{
#define fVslider0 (*fVslider0_)
#define fVslider1 (*fVslider1_)
#define fVslider2 (*fVslider2_)
#define fVslider3 (*fVslider3_)
	float fSlow0 = (0.000366769877f * (std::exp((3.0f * float(fVslider0))) + -1.0f));
	float fSlow1 = (0.00700000022f * float(fVslider1));
	float fSlow2 = (0.00700000022f * float(fVslider2));
	float fSlow3 = (0.000366769877f * (std::exp((3.0f * float(fVslider3))) + -1.0f));
	for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
		fRec3[0] = (fSlow0 + (0.992999971f * fRec3[1]));
		float fTemp0 = float(input0[i0]);
		fVec0[0] = fTemp0;
		float fTemp1 = (0.000442226388f * fRec3[0]);
		fRec2[0] = (0.0f - (((fRec2[1] * (((fConst9 * fRec3[0]) + 0.00221115421f) - fConst10)) - (fConst0 * ((fTemp0 * ((0.0f - fTemp1) + -2.07846406e-05f)) + (fVec0[1] * (fTemp1 + 2.07846406e-05f))))) / (fConst10 + ((fConst11 * fRec3[0]) + 0.00221115421f))));
		fRec4[0] = (fSlow1 + (0.992999971f * fRec4[1]));
		fRec7[0] = (fSlow2 + (0.992999971f * fRec7[1]));
		float fTemp2 = (fConst20 * fRec7[0]);
		float fTemp3 = (fConst0 * (0.0f - (5.63050606e-10f * fRec7[0])));
		fRec6[0] = (0.0f - ((((fRec6[1] * ((fConst15 * ((fRec7[0] * ((0.0f - (2.0270341e-09f * fRec7[0])) + 4.6621782e-09f)) + -2.68075251e-09f)) + 1.04699353e-07f)) + (fRec6[2] * ((fConst0 * (fConst17 + (fRec7[0] * (fConst19 + fTemp2)))) + 5.23496766e-08f))) - (((fRec2[2] * ((fConst0 * (fConst22 + (fRec7[0] * (fConst24 + fTemp3)))) + -2.90826115e-18f)) + (fRec2[1] * ((fConst15 * ((fRec7[0] * ((1.12610121e-09f * fRec7[0]) + -2.59003285e-09f)) + 1.48926893e-09f)) + -5.81652231e-18f))) + (fRec2[0] * ((fConst0 * (fConst25 + (fRec7[0] * (fConst26 + fTemp3)))) + -2.90826115e-18f)))) / ((fConst0 * (fConst27 + (fRec7[0] * (fConst28 + fTemp2)))) + 5.23496766e-08f)));
		fRec8[0] = (fSlow3 + (0.992999971f * fRec8[1]));
		fRec5[0] = (0.0f - (fConst13 * ((fConst14 * fRec5[1]) - (fConst0 * ((fRec6[0] * (0.0f - (9.65139043e-05f * fRec8[0]))) + (9.65139043e-05f * (fRec8[0] * fRec6[1])))))));
		float fElse0 = float(harmonic_exciterclip(float(fRec5[0])));
		float fTemp4 = ((fRec2[0] * fRec4[0]) + (int(signbit(float(fRec5[0]))) ? fElse0 : fRec5[0]));
		fVec1[0] = fTemp4;
		fRec1[0] = (0.0f - (fConst4 * ((fConst5 * fRec1[1]) - ((fConst7 * fTemp4) + (fConst6 * fVec1[1])))));
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
		fVslider0_ = static_cast<float*>(data); // , 0.5f, 0.0f, 1.0f, 0.00999999978f 
		break;
	case BPF: 
		fVslider2_ = static_cast<float*>(data); // , 0.5f, 0.0f, 1.0f, 0.00999999978f 
		break;
	case DIRECT: 
		fVslider1_ = static_cast<float*>(data); // , 0.5f, 0.0f, 1.0f, 0.00999999978f 
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
