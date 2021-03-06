{
  description = ''A SIMD-accelerated vector library written in C99 with Nim bindings.'';

  inputs.flakeNimbleLib.owner = "riinr";
  inputs.flakeNimbleLib.ref   = "master";
  inputs.flakeNimbleLib.repo  = "nim-flakes-lib";
  inputs.flakeNimbleLib.type  = "github";
  inputs.flakeNimbleLib.inputs.nixpkgs.follows = "nixpkgs";
  
  inputs."sol-devel".dir   = "devel";
  inputs."sol-devel".owner = "nim-nix-pkgs";
  inputs."sol-devel".ref   = "master";
  inputs."sol-devel".repo  = "sol";
  inputs."sol-devel".type  = "github";
  inputs."sol-devel".inputs.nixpkgs.follows = "nixpkgs";
  inputs."sol-devel".inputs.flakeNimbleLib.follows = "flakeNimbleLib";
  
  inputs."sol-master".dir   = "master";
  inputs."sol-master".owner = "nim-nix-pkgs";
  inputs."sol-master".ref   = "master";
  inputs."sol-master".repo  = "sol";
  inputs."sol-master".type  = "github";
  inputs."sol-master".inputs.nixpkgs.follows = "nixpkgs";
  inputs."sol-master".inputs.flakeNimbleLib.follows = "flakeNimbleLib";
  
  outputs = { self, nixpkgs, flakeNimbleLib, ...}@inputs:
  let 
    lib  = flakeNimbleLib.lib;
    args = ["self" "nixpkgs" "flakeNimbleLib"];
  in lib.mkProjectOutput {
    inherit self nixpkgs;
    meta = builtins.fromJSON (builtins.readFile ./meta.json);
    refs = builtins.removeAttrs inputs args;
  };
}