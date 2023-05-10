{ lib
, stdenvNoCC
, clang
, gnumake
, kel-test
}:

stdenvNoCC.mkDerivation {
  pname = "kel-test-example";
  version = "0.0.0";

  src = ./..;

  nativeBuildInputs = [
    clang
    gnumake
    kel-test
  ];

  installPhase = ''
    PREFIX=$out make install
  '';

  output = [ "out" ];
}
