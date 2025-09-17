import { defineConfig } from "tsdown";

export default defineConfig({
  entry: "lib/index.ts",
  format: ["cjs", "esm"],
  dts: true,
  clean: true,
  sourcemap: true,
  minify: false,
  target: "node18",
  outDir: "dist",
  external: ["node-addon-api", "node-gyp", "node-gyp-build"],
  treeshake: true,
});
