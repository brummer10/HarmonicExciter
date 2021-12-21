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
	float fVec0[2];
	float fConst3;
	float fRec3[2];
	float fConst5;
	FAUSTFLOAT fVslider1;
	FAUSTFLOAT	*fVslider1_;
	float fRec4[2];
	float fConst6;
	float fConst7;
	float fRec2[2];
	float fConst10;
	float fConst11;
	FAUSTFLOAT fVslider2;
	FAUSTFLOAT	*fVslider2_;
	float fRec7[2];
	float fConst13;
	float fConst15;
	float fConst16;
	float fConst17;
	float fConst18;
	float fRec6[3];
	float fConst20;
	float fConst22;
	float fConst23;
	float fConst24;
	float fConst25;
	float fRec5[2];
	FAUSTFLOAT fVslider3;
	FAUSTFLOAT	*fVslider3_;
	float fRec8[2];
	float fVec1[2];
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
	for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) fVec0[l1] = 0.0f;
	for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) fRec3[l2] = 0.0f;
	for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) fRec4[l3] = 0.0f;
	for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) fRec2[l4] = 0.0f;
	for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) fRec7[l5] = 0.0f;
	for (int l6 = 0; (l6 < 3); l6 = (l6 + 1)) fRec6[l6] = 0.0f;
	for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) fRec5[l7] = 0.0f;
	for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) fRec8[l8] = 0.0f;
	for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) fVec1[l9] = 0.0f;
	for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) fRec0[l10] = 0.0f;
}

inline void Dsp::init(uint32_t sample_rate)
{
	fSampleRate = sample_rate;
	fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
	float fConst1 = (3.14159274f / fConst0);
	fConst2 = (1.0f / (fConst1 + 1.0f));
	fConst3 = (1.0f - fConst1);
	float fConst4 = (4.42226389e-09f * fConst0);
	fConst5 = (3.36313397e-23f - fConst4);
	fConst6 = (2.07850571e-05f * fConst0);
	fConst7 = (fConst4 + 3.36313397e-23f);
	float fConst8 = (2.07413941e-05f * fConst0);
	float fConst9 = (fConst8 + 0.00441306271f);
	fConst10 = (fConst0 / fConst9);
	fConst11 = mydsp_faustpower2_f(fConst0);
	float fConst12 = (1.33399736e-09f * fConst0);
	fConst13 = (fConst12 + -6.67044276e-07f);
	float fConst14 = (2.31999531e-09f * fConst0);
	fConst15 = (5.80038545e-07f - fConst14);
	fConst16 = (1.00869368e-09f * fConst0);
	fConst17 = (fConst12 + 6.67044276e-07f);
	fConst18 = (-5.80038545e-07f - fConst14);
	float fConst19 = (7.41090689e-10f * fConst0);
	fConst20 = (-1.46605612e-12f - fConst19);
	float fConst21 = (1.28885336e-09f * fConst0);
	fConst22 = (fConst21 + 1.27483137e-12f);
	fConst23 = (1.46605612e-12f - fConst19);
	fConst24 = (fConst21 + -1.27483137e-12f);
	fConst25 = ((0.00441306271f - fConst8) / fConst9);
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
		float fTemp0 = float(input0[i0]);
		fVec0[0] = fTemp0;
		fRec3[0] = (fConst2 * ((fTemp0 - fVec0[1]) + (fConst3 * fRec3[1])));
		fRec4[0] = (fSlow1 + (0.992999971f * fRec4[1]));
		float fTemp1 = (fConst6 + ((fConst7 * fRec4[0]) + 0.00221115421f));
		fRec2[0] = (fRec3[0] - ((fRec2[1] * (((fConst5 * fRec4[0]) + 0.00221115421f) - fConst6)) / fTemp1));
		float fTemp2 = (0.000442226388f * fRec4[0]);
		float fTemp3 = ((fRec2[0] * ((0.0f - fTemp2) + -2.07846406e-05f)) + (fRec2[1] * (fTemp2 + 2.07846406e-05f)));
		fRec7[0] = (fSlow2 + (0.992999971f * fRec7[1]));
		float fTemp4 = (fConst16 * fRec7[0]);
		float fTemp5 = ((fConst0 * (fConst17 + (fRec7[0] * (fConst18 + fTemp4)))) + 5.21008907e-08f);
		fRec6[0] = ((fConst0 * (fTemp3 / fTemp1)) - (((fRec6[1] * ((fConst11 * ((fRec7[0] * ((0.0f - (2.01738737e-09f * fRec7[0])) + 4.63999061e-09f)) + -2.66799471e-09f)) + 1.04201781e-07f)) + (fRec6[2] * ((fConst0 * (fConst13 + (fRec7[0] * (fConst15 + fTemp4)))) + 5.21008907e-08f))) / fTemp5));
		float fTemp6 = (fConst0 * (0.0f - (5.60371027e-10f * fRec7[0])));
		fRec5[0] = (((((fRec6[0] * ((fConst0 * (fConst20 + (fRec7[0] * (fConst22 + fTemp6)))) + -2.89442056e-18f)) + (fRec6[1] * ((fConst11 * ((fRec7[0] * ((1.12074205e-09f * fRec7[0]) + -2.57770671e-09f)) + 1.48218138e-09f)) + -5.78884112e-18f))) + (fRec6[2] * ((fConst0 * (fConst23 + (fRec7[0] * (fConst24 + fTemp6)))) + -2.89442056e-18f))) / fTemp5) - (fConst25 * fRec5[1]));
		fRec8[0] = (fSlow3 + (0.992999971f * fRec8[1]));
		float fTemp7 = (fConst10 * ((fRec5[0] * (0.0f - (9.65139043e-05f * fRec8[0]))) + (9.65139043e-05f * (fRec8[0] * fRec5[1]))));
		float fElse0 = float(harmonic_exciterclip(float(fTemp7)));
		float fTemp8 = ((fConst0 * ((fRec1[0] * fTemp3) / fTemp1)) + (int(signbit(float(fTemp7))) ? fElse0 : fTemp7));
		fVec1[0] = fTemp8;
		fRec0[0] = (fConst2 * ((fTemp8 - fVec1[1]) + (fConst3 * fRec0[1])));
		output0[i0] = FAUSTFLOAT(fRec0[0]);
		fRec1[1] = fRec1[0];
		fVec0[1] = fVec0[0];
		fRec3[1] = fRec3[0];
		fRec4[1] = fRec4[0];
		fRec2[1] = fRec2[0];
		fRec7[1] = fRec7[0];
		fRec6[2] = fRec6[1];
		fRec6[1] = fRec6[0];
		fRec5[1] = fRec5[0];
		fRec8[1] = fRec8[0];
		fVec1[1] = fVec1[0];
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
