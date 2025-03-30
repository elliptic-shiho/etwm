with rec {
  pkgs = import <nixpkgs> {};
};

pkgs.stdenv.mkDerivation {
  name = "etwm";
  src = ./.;
  buildInputs = [
    pkgs.bison
    pkgs.xorg.libX11
    pkgs.xorg.libXext
    pkgs.xorg.libXt
    pkgs.xorg.libXmu
    pkgs.xorg.libXrandr
    pkgs.xorg.libXinerama
    pkgs.xorg.xbitmaps
    pkgs.flex
  ];

  installPhase = ''
    mkdir -p $out/bin
    cp ./bin/twm $out/bin/etwm
  '';
}
