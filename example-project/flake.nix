{
  description = "Simple clang devshell flake";

  inputs.nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  inputs.cash.url = "github:vicnotor/cash";

  outputs = {
    self,
    nixpkgs,
    cash,
  }: let
    supportedSystems = ["x86_64-linux" "aarch64-linux" "x86_64-darwin" "aarch64-darwin"];
    forEachSupportedSystem = f:
      nixpkgs.lib.genAttrs supportedSystems (system: let
        pkgs = import nixpkgs {inherit system;};
        lib = pkgs.lib;
      in
        f {inherit pkgs lib;});
  in {
    devShells = forEachSupportedSystem ({pkgs, ...}: {
      default =
        pkgs.mkShell
        {
          packages = with pkgs; [
            gcc
            gdb
            clang
            clang-tools
            xorg.libX11
            libpng
            zlib
          ];
          shellHook = ''
            echo "Generating .clangd with correct include paths..."

            INCLUDE_PATHS=$(clang -E -x c - -v < /dev/null 2>&1 \
              | sed -n '/#include <...> search starts here:/,/End of search list./p' \
              | grep -v '^#' \
              | grep -v 'End of search list.' \
              | sed 's/^ \{1,\}//' \
              | sed 's/.*/"-isystem", "&"/' \
              | paste -sd, -)

            cat > .clangd <<EOF
            CompileFlags:
              Add: [''${INCLUDE_PATHS}]
            EOF

            echo ".clangd generated:"
            cat .clangd
          '';
        };
    });
    packages = forEachSupportedSystem ({
      pkgs,
      lib,
    }: rec {
      default = pkgs.stdenv.mkDerivation {
        pname = "life";
        version = "1.0";

        src = ./.;

        buildInputs = with pkgs; [
          gcc
          xorg.libX11
          libpng
          zlib
          cash.packages.${pkgs.system}.default
        ];

        # Set INSTALL_ROOT to $out so the Makefile install goes into the right place
        makeFlags = ["INSTALL_ROOT=$(out)"];

        LDFLAGS = lib.concatStringsSep " " [
          "-L${pkgs.xorg.libX11}/lib"
        ];

        buildPhase = ''
          make life
        '';

        installPhase = ''
          mkdir -p $out/bin
          cp life $out/bin/
        '';
      };

      life = default;
    });
  };
}
