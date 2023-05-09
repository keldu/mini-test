{ lib
, stdenvNoCC
, clang
, gnumake
}:

stdenvNoCC.mkDerivation {
  pname = "kel-test";
  version = "0.0.0";

  src = ./..;

  nativeBuildInputs = [
    clang
    gnumake
  ];

  installPhase = ''
    PREFIX=$out make install
  '';

  output = [ "out" ];
}
