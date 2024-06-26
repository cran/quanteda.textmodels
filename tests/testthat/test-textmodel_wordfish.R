library("quanteda")

ie2010dfm <- dfm(tokens(data_corpus_irishbudget2010))
wfm <- textmodel_wordfish(ie2010dfm, dir = c(6,5))
wfs <- summary(wfm)
wfp <- predict(wfm)

test_that("textmodel-wordfish (sparse) works as expected as austin::wordfish", {
    skip_if_not_installed("austin")
    wfmodelAustin <- austin::wordfish(convert(ie2010dfm, to = "austin"), 
                                      dir = c(6, 5))
    cc <- cor(wfm$theta, wfmodelAustin$theta)
    expect_gt(cc, 0.99)
})

# test_that("textmodel-wordfish works as expected: dense vs sparse vs sparse+mt", {
#     cc <- cor(wfm_d$theta, wfm$theta)
#     expect_gt(cc, 0.99)
# })

test_that("print/show/summary method works as expected", {
    expect_output(
        print(wfm),
        "^\\nCall:\\ntextmodel_wordfish\\.dfm\\(.*Dispersion.*14 documents; 514\\d features\\.$"
    )
    expect_output(
        print(wfs),
        "^\\nCall:\\ntextmodel_wordfish\\.dfm\\("
    )
    expect_output(
        print(wfs),
        "Estimated Document Positions:"
    )
    expect_output(
        print(wfs),
        "Estimated Feature Scores:"
    )
})

test_that("coef works for wordfish fitted", {
    expect_equivalent(coef(wfm, margin = "features")[, "beta"], wfm$beta, tolerance = 1e-8)
    expect_equivalent(coef(wfm, margin = "features")[, "psi"], wfm$psi, tolerance = 1e-8)
    expect_equivalent(coef(wfm, margin = "documents")[, "alpha"], wfm$alpha, tolerance = 1e-8)
    expect_equivalent(coef(wfm, margin = "documents")[, "theta"], wfm$theta, tolerance = 1e-8)
    expect_is(coef(wfm, margin = "both"), "list")
    expect_equal(length(coef(wfm, margin = "both")), 2)
    expect_equal(names(coef(wfm, margin = "both")), c("documents", "features"))
    
    # "for wordfish, coef and coefficients are the same", {
    expect_equal(coef(wfm), coefficients(wfm))
})

test_that("test wordfish predict methods", {
    pr <- predict(wfm)
    expect_equal(pr[1], c("Lenihan, Brian (FF)" = 1.82), tolerance = .01)
    
    pr2 <- predict(wfm, se.fit = TRUE)
    expect_is(pr2, "list")
    expect_equal(names(pr2), c("fit", "se.fit"))
    expect_equal(pr2$se.fit[1], 0.019, tolerance = .01)
    
    pr3 <- predict(wfm, se.fit = TRUE, interval = "confidence")
    expect_equal(names(pr3), c("fit", "se.fit"))
})

test_that("raises error when dfm is empty (#1419)",  {
    mx <- dfm_trim(data_dfm_lbgexample, 1000)
    expect_error(textmodel_wordfish(mx),
                 quanteda.textmodels:::message_error("dfm_empty"))
})
