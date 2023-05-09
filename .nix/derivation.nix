{ lib
, stdenvNoCC
, clang
}:

stdenvNoCC.mkDerivation {
  pname = "kel-test";
  version = "0.0.0";

  src = ./..;

  nativeBuildInputs = [
    clang
    gnumake
  ];

  output = [ "out" "dev" ];
}
