// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

// analyze
Rcpp::List analyze(std::vector<double> x, float bands_per_octave, float frequency_min, float frequency_max, float samplerate_hz, std::string mother_wavelet, float morlet_carrier, unsigned int paul_order, int cores, std::string optimisation);
RcppExport SEXP _RcppWavelet_analyze(SEXP xSEXP, SEXP bands_per_octaveSEXP, SEXP frequency_minSEXP, SEXP frequency_maxSEXP, SEXP samplerate_hzSEXP, SEXP mother_waveletSEXP, SEXP morlet_carrierSEXP, SEXP paul_orderSEXP, SEXP coresSEXP, SEXP optimisationSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::vector<double> >::type x(xSEXP);
    Rcpp::traits::input_parameter< float >::type bands_per_octave(bands_per_octaveSEXP);
    Rcpp::traits::input_parameter< float >::type frequency_min(frequency_minSEXP);
    Rcpp::traits::input_parameter< float >::type frequency_max(frequency_maxSEXP);
    Rcpp::traits::input_parameter< float >::type samplerate_hz(samplerate_hzSEXP);
    Rcpp::traits::input_parameter< std::string >::type mother_wavelet(mother_waveletSEXP);
    Rcpp::traits::input_parameter< float >::type morlet_carrier(morlet_carrierSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type paul_order(paul_orderSEXP);
    Rcpp::traits::input_parameter< int >::type cores(coresSEXP);
    Rcpp::traits::input_parameter< std::string >::type optimisation(optimisationSEXP);
    rcpp_result_gen = Rcpp::wrap(analyze(x, bands_per_octave, frequency_min, frequency_max, samplerate_hz, mother_wavelet, morlet_carrier, paul_order, cores, optimisation));
    return rcpp_result_gen;
END_RCPP
}
// getScales
arma::vec getScales(float bands_per_octave, float frequency_min, float frequency_max, float samplerate_hz);
RcppExport SEXP _RcppWavelet_getScales(SEXP bands_per_octaveSEXP, SEXP frequency_minSEXP, SEXP frequency_maxSEXP, SEXP samplerate_hzSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< float >::type bands_per_octave(bands_per_octaveSEXP);
    Rcpp::traits::input_parameter< float >::type frequency_min(frequency_minSEXP);
    Rcpp::traits::input_parameter< float >::type frequency_max(frequency_maxSEXP);
    Rcpp::traits::input_parameter< float >::type samplerate_hz(samplerate_hzSEXP);
    rcpp_result_gen = Rcpp::wrap(getScales(bands_per_octave, frequency_min, frequency_max, samplerate_hz));
    return rcpp_result_gen;
END_RCPP
}
// getSize
std::size_t getSize(float bands_per_octave, float frequency_min, float frequency_max, float samplerate_hz);
RcppExport SEXP _RcppWavelet_getSize(SEXP bands_per_octaveSEXP, SEXP frequency_minSEXP, SEXP frequency_maxSEXP, SEXP samplerate_hzSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< float >::type bands_per_octave(bands_per_octaveSEXP);
    Rcpp::traits::input_parameter< float >::type frequency_min(frequency_minSEXP);
    Rcpp::traits::input_parameter< float >::type frequency_max(frequency_maxSEXP);
    Rcpp::traits::input_parameter< float >::type samplerate_hz(samplerate_hzSEXP);
    rcpp_result_gen = Rcpp::wrap(getSize(bands_per_octave, frequency_min, frequency_max, samplerate_hz));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_RcppWavelet_analyze", (DL_FUNC) &_RcppWavelet_analyze, 10},
    {"_RcppWavelet_getScales", (DL_FUNC) &_RcppWavelet_getScales, 4},
    {"_RcppWavelet_getSize", (DL_FUNC) &_RcppWavelet_getSize, 4},
    {NULL, NULL, 0}
};

RcppExport void R_init_RcppWavelet(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
