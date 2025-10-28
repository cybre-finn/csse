{
  description = "C dev shell";

  outputs = { self, nixpkgs }: {
    devShells.x86_64-linux.default = let
      pkgs = import nixpkgs { system = "x86_64-linux"; };
    in pkgs.mkShell {
      packages = with pkgs; [
        gcc
        gnumake 
        binutils
        pkg-config
        clang-tools
	python314
      ];
    };
  };
}
