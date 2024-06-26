// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// cpp_ca
S4 cpp_ca(const arma::sp_mat& dfm, const double residual_floor);
RcppExport SEXP _quanteda_textmodels_cpp_ca(SEXP dfmSEXP, SEXP residual_floorSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::sp_mat& >::type dfm(dfmSEXP);
    Rcpp::traits::input_parameter< const double >::type residual_floor(residual_floorSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_ca(dfm, residual_floor));
    return rcpp_result_gen;
END_RCPP
}
// cpp_svmlin
List cpp_svmlin(S4 X, NumericVector y, int l, int algorithm, double lambda, double lambda_u, int max_switch, double pos_frac, double Cp, double Cn, NumericVector costs, bool verbose);
RcppExport SEXP _quanteda_textmodels_cpp_svmlin(SEXP XSEXP, SEXP ySEXP, SEXP lSEXP, SEXP algorithmSEXP, SEXP lambdaSEXP, SEXP lambda_uSEXP, SEXP max_switchSEXP, SEXP pos_fracSEXP, SEXP CpSEXP, SEXP CnSEXP, SEXP costsSEXP, SEXP verboseSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< S4 >::type X(XSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type y(ySEXP);
    Rcpp::traits::input_parameter< int >::type l(lSEXP);
    Rcpp::traits::input_parameter< int >::type algorithm(algorithmSEXP);
    Rcpp::traits::input_parameter< double >::type lambda(lambdaSEXP);
    Rcpp::traits::input_parameter< double >::type lambda_u(lambda_uSEXP);
    Rcpp::traits::input_parameter< int >::type max_switch(max_switchSEXP);
    Rcpp::traits::input_parameter< double >::type pos_frac(pos_fracSEXP);
    Rcpp::traits::input_parameter< double >::type Cp(CpSEXP);
    Rcpp::traits::input_parameter< double >::type Cn(CnSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type costs(costsSEXP);
    Rcpp::traits::input_parameter< bool >::type verbose(verboseSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_svmlin(X, y, l, algorithm, lambda, lambda_u, max_switch, pos_frac, Cp, Cn, costs, verbose));
    return rcpp_result_gen;
END_RCPP
}
// cpp_wordfish_dense
Rcpp::List cpp_wordfish_dense(SEXP wfm, SEXP dir, SEXP priors, SEXP tol, SEXP disp, SEXP dispfloor, bool abs_err);
RcppExport SEXP _quanteda_textmodels_cpp_wordfish_dense(SEXP wfmSEXP, SEXP dirSEXP, SEXP priorsSEXP, SEXP tolSEXP, SEXP dispSEXP, SEXP dispfloorSEXP, SEXP abs_errSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type wfm(wfmSEXP);
    Rcpp::traits::input_parameter< SEXP >::type dir(dirSEXP);
    Rcpp::traits::input_parameter< SEXP >::type priors(priorsSEXP);
    Rcpp::traits::input_parameter< SEXP >::type tol(tolSEXP);
    Rcpp::traits::input_parameter< SEXP >::type disp(dispSEXP);
    Rcpp::traits::input_parameter< SEXP >::type dispfloor(dispfloorSEXP);
    Rcpp::traits::input_parameter< bool >::type abs_err(abs_errSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_wordfish_dense(wfm, dir, priors, tol, disp, dispfloor, abs_err));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_quanteda_textmodels_cpp_ca", (DL_FUNC) &_quanteda_textmodels_cpp_ca, 2},
    {"_quanteda_textmodels_cpp_svmlin", (DL_FUNC) &_quanteda_textmodels_cpp_svmlin, 12},
    {"_quanteda_textmodels_cpp_wordfish_dense", (DL_FUNC) &_quanteda_textmodels_cpp_wordfish_dense, 7},
    {NULL, NULL, 0}
};

RcppExport void R_init_quanteda_textmodels(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
