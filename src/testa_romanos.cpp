// Copyright [2020] <Copyright Joao Pedro>
#define CATCH_CONFIG_MAIN
#include "../include/romanos.hpp"

// Primeiro Teste: Entrada de letras
TEST_CASE("checkString", "[checkString]") {
    REQUIRE(checkString("Xsdsd23") == false);
    REQUIRE(checkString("Xsdsd!") == false);
    REQUIRE(checkString("Xsds1d") == false);
    REQUIRE(checkString("XVi") == false);
    REQUIRE(checkString("CxII") == false);
    REQUIRE(checkString("XXII") == true);
    REQUIRE(checkString("CXII") == true);
    REQUIRE(checkString("XV") == true);
    REQUIRE(checkString("XXII") == true);
    REQUIRE(checkString("CXXII") == true);
}
