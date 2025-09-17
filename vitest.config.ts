import { defineConfig } from "vitest/config";
import { resolve } from "path";

export default defineConfig({
  test: {
    globals: true,
    environment: "node",
    include: ["test/**/*.{test,spec}.{js,ts}"],
    exclude: ["node_modules", "dist", "build"],
    coverage: {
      provider: "v8",
      reporter: ["text", "json", "html"],
      exclude: [
        "node_modules/",
        "dist/",
        "build/",
        "deps/",
        "examples/",
        "raw-samples-repo/",
        "toolchains/",
        "output/",
        "**/*.d.ts",
        "**/*.config.*",
      ],
    },
    testTimeout: 10000,
    hookTimeout: 10000,
    // 添加更多配置来防止卡住
    bail: 1, // 遇到第一个失败就停止
    maxConcurrency: 1, // 限制并发数
    pool: "threads", // 使用线程池
    poolOptions: {
      threads: {
        singleThread: true, // 单线程运行
      },
    },
  },
  resolve: {
    alias: {
      "@": resolve(__dirname, "./src"),
      "@lib": resolve(__dirname, "./lib"),
      "@test": resolve(__dirname, "./test"),
    },
  },
});
