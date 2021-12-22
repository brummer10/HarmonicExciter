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
	float fConst3;
	float fConst6;
	float fConst7;
	float fConst8;
	FAUSTFLOAT fVslider0;
	FAUSTFLOAT	*fVslider0_;
	float fRec3[2];
	float fConst10;
	FAUSTFLOAT fVslider1;
	FAUSTFLOAT	*fVslider1_;
	float fRec5[2];
	float fConst11;
	float fConst12;
	float fRec4[2];
	float fConst15;
	float fConst17;
	float fConst18;
	float fVec0[2];
	float fRec8[2];
	float fConst19;
	FAUSTFLOAT fVslider2;
	FAUSTFLOAT	*fVslider2_;
	float fRec9[2];
	float fConst21;
	float fConst23;
	float fConst24;
	float fConst25;
	float fConst26;
	float fRec7[3];
	float fConst28;
	float fConst30;
	float fConst31;
	float fConst32;
	float fConst33;
	float fRec6[2];
	FAUSTFLOAT fVslider3;
	FAUSTFLOAT	*fVslider3_;
	float fRec10[2];
	float fVec1[2];
	float fRec2[2];
	float fConst34;
	float fRec1[2];
	float fVec2[2];
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
	for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) fRec5[l1] = 0.0f;
	for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) fRec4[l2] = 0.0f;
	for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) fVec0[l3] = 0.0f;
	for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) fRec8[l4] = 0.0f;
	for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) fRec9[l5] = 0.0f;
	for (int l6 = 0; (l6 < 3); l6 = (l6 + 1)) fRec7[l6] = 0.0f;
	for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) fRec6[l7] = 0.0f;
	for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) fRec10[l8] = 0.0f;
	for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) fVec1[l9] = 0.0f;
	for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) fRec2[l10] = 0.0f;
	for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) fRec1[l11] = 0.0f;
	for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) fVec2[l12] = 0.0f;
	for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) fRec0[l13] = 0.0f;
}

inline void Dsp::init(uint32_t sample_rate)
{
	fSampleRate = sample_rate;
	fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
	float fConst1 = (3.14159274f / fConst0);
	fConst2 = (1.0f / (fConst1 + 1.0f));
	fConst3 = (1.0f - fConst1);
	float fConst4 = (2.08331167e-05f * fConst0);
	float fConst5 = (fConst4 + 1.04165583e-05f);
	fConst6 = (1.0f / fConst5);
	fConst7 = (2.08327001e-05f * fConst0);
	fConst8 = (0.0f - fConst7);
	float fConst9 = (4.42226389e-09f * fConst0);
	fConst10 = (3.36313397e-23f - fConst9);
	fConst11 = (2.07850571e-05f * fConst0);
	fConst12 = (fConst9 + 3.36313397e-23f);
	float fConst13 = (2.07413941e-05f * fConst0);
	float fConst14 = (fConst13 + 0.00441306271f);
	fConst15 = (fConst0 / fConst14);
	float fConst16 = (0.0314159282f / fConst0);
	fConst17 = (1.0f / (fConst16 + 1.0f));
	fConst18 = (1.0f - fConst16);
	fConst19 = mydsp_faustpower2_f(fConst0);
	float fConst20 = (1.34037625e-09f * fConst0);
	fConst21 = (fConst20 + -4.93981247e-07f);
	float fConst22 = (2.3310891e-09f * fConst0);
	fConst23 = (4.29548919e-07f - fConst22);
	fConst24 = (1.01351705e-09f * fConst0);
	fConst25 = (fConst20 + 4.93981247e-07f);
	fConst26 = (-4.29548919e-07f - fConst22);
	float fConst27 = (7.44634465e-10f * fConst0);
	fConst28 = (-1.47306646e-12f - fConst27);
	float fConst29 = (1.29501643e-09f * fConst0);
	fConst30 = (fConst29 + 1.2809274e-12f);
	fConst31 = (1.47306646e-12f - fConst27);
	fConst32 = (fConst29 + -1.2809274e-12f);
	fConst33 = ((0.00441306271f - fConst13) / fConst14);
	fConst34 = ((1.04165583e-05f - fConst4) / fConst5);
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
		fRec3[0] = (fSlow0 + (0.992999971f * fRec3[1]));
		fRec5[0] = (fSlow1 + (0.992999971f * fRec5[1]));
		float fTemp0 = (fConst11 + ((fConst12 * fRec5[0]) + 0.00221115421f));
		fRec4[0] = (float(input0[i0]) - ((fRec4[1] * (((fConst10 * fRec5[0]) + 0.00221115421f) - fConst11)) / fTemp0));
		float fTemp1 = (0.000442226388f * fRec5[0]);
		float fTemp2 = ((fRec4[0] * ((0.0f - fTemp1) + -2.07846406e-05f)) + (fRec4[1] * (fTemp1 + 2.07846406e-05f)));
		float fTemp3 = (fTemp2 / fTemp0);
		fVec0[0] = fTemp3;
		fRec8[0] = (fConst17 * ((fConst18 * fRec8[1]) + (fConst0 * (fTemp3 - fVec0[1]))));
		fRec9[0] = (fSlow2 + (0.992999971f * fRec9[1]));
		float fTemp4 = (fConst24 * fRec9[0]);
		float fTemp5 = ((fConst0 * (fConst25 + (fRec9[0] * (fConst26 + fTemp4)))) + 5.23496766e-08f);
		fRec7[0] = (fRec8[0] - (((fRec7[1] * ((fConst19 * ((fRec9[0] * ((0.0f - (2.0270341e-09f * fRec9[0])) + 4.6621782e-09f)) + -2.68075251e-09f)) + 1.04699353e-07f)) + (fRec7[2] * ((fConst0 * (fConst21 + (fRec9[0] * (fConst23 + fTemp4)))) + 5.23496766e-08f))) / fTemp5));
		float fTemp6 = (fConst0 * (0.0f - (5.63050606e-10f * fRec9[0])));
		fRec6[0] = (((((fRec7[0] * ((fConst0 * (fConst28 + (fRec9[0] * (fConst30 + fTemp6)))) + -2.90826115e-18f)) + (fRec7[1] * ((fConst19 * ((fRec9[0] * ((1.12610121e-09f * fRec9[0]) + -2.59003285e-09f)) + 1.48926893e-09f)) + -5.81652231e-18f))) + (fRec7[2] * ((fConst0 * (fConst31 + (fRec9[0] * (fConst32 + fTemp6)))) + -2.90826115e-18f))) / fTemp5) - (fConst33 * fRec6[1]));
		fRec10[0] = (fSlow3 + (0.992999971f * fRec10[1]));
		float fTemp7 = (fConst15 * ((fRec6[0] * (0.0f - (9.65139043e-05f * fRec10[0]))) + (9.65139043e-05f * (fRec10[0] * fRec6[1]))));
		float fElse0 = float(harmonic_exciterclip(float(fTemp7)));
		float fTemp8 = ((fConst0 * ((fRec3[0] * fTemp2) / fTemp0)) + (int(signbit(float(fTemp7))) ? fElse0 : fTemp7));
		fVec1[0] = fTemp8;
		fRec2[0] = (fConst2 * ((fTemp8 - fVec1[1]) + (fConst3 * fRec2[1])));
		fRec1[0] = (fRec2[0] - (fConst34 * fRec1[1]));
		float fTemp9 = ((fConst8 * fRec1[0]) + (fConst7 * fRec1[1]));
		fVec2[0] = fTemp9;
		fRec0[0] = (fConst2 * ((fConst3 * fRec0[1]) + (fConst6 * (fTemp9 - fVec2[1]))));
		output0[i0] = FAUSTFLOAT(fRec0[0]);
		fRec3[1] = fRec3[0];
		fRec5[1] = fRec5[0];
		fRec4[1] = fRec4[0];
		fVec0[1] = fVec0[0];
		fRec8[1] = fRec8[0];
		fRec9[1] = fRec9[0];
		fRec7[2] = fRec7[1];
		fRec7[1] = fRec7[0];
		fRec6[1] = fRec6[0];
		fRec10[1] = fRec10[0];
		fVec1[1] = fVec1[0];
		fRec2[1] = fRec2[0];
		fRec1[1] = fRec1[0];
		fVec2[1] = fVec2[0];
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
