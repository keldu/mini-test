{ lib
, clang
}:

stdenvNoCC.mkDerivation {
  pname = "kel-test";
  version = "0.0.0";

  src = ./..;

  nativeBuildInputs = [
    clang
  ];

  output = [ "out" "dev" ];
}
