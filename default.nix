{ pkgs ? import <nixpkgs> {}
}:

pkgs.callPackage ./.nix/derivation.nix {}
