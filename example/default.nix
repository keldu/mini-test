{ pkgs ? import <nixpkgs> {}
}:

let
  kel-test = pkgs.callPackage ./../.nix/derivation.nix {};
in pkgs.callPackage ./.nix/derivation.nix {
  inherit kel-test;
}
