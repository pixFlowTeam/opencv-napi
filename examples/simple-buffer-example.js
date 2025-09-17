const OpenCV = require("../lib/index");
const fs = require("fs");

/**
 * 简单缓冲区 API 示例
 *
 * 演示新缓冲区 API 的最常见用例：
 * - 为 Web 使用创建 JPEG 缓冲区
 * - 在内存中创建缩略图
 * - 使用缓冲区而不是文件
 */

async function simpleBufferExample(inputFile) {
  console.log("📸 Simple Buffer API Example");
  console.log("============================");
  console.log(`📁 Processing: ${inputFile}\n`);

  const processor = new OpenCV();

  try {
    // 加载并处理 图像文件
    console.log("🔄 Loading RAW file...");
    await processor.imread(inputFile);

    console.log("⚙️ Processing image...");
    await processor.processImage();

    // ============== 示例 1：为 Web 使用创建 JPEG 缓冲区 ==============
    console.log("\n📸 Creating web-optimized JPEG buffer...");
    const webJpeg = await processor.createJPEGBuffer({
      quality: 85,
      width: 1920, // 调整到 1920px 宽度
      progressive: true, // 更适合 Web 加载
    });

    console.log(`✅ Web JPEG created: ${webJpeg.buffer.length} bytes`);
    console.log(
      `   Size: ${webJpeg.metadata.outputDimensions.width}x${webJpeg.metadata.outputDimensions.height}`
    );
    console.log(
      `   Compression: ${webJpeg.metadata.fileSize.compressionRatio}:1`
    );

    // ============== 示例 2：创建缩略图缓冲区 ==============
    console.log("\n🔍 Creating thumbnail buffer...");
    const thumbnail = await processor.createThumbnailJPEGBuffer({
      quality: 85,
      maxSize: 300, // 任意边最大 300px
    });

    console.log(`✅ Thumbnail created: ${thumbnail.buffer.length} bytes`);
    console.log(
      `   Size: ${thumbnail.metadata.outputDimensions.width}x${thumbnail.metadata.outputDimensions.height}`
    );

    // ============== 示例 3：为存储创建高质量缓冲区 ==============
    console.log("\n🎨 Creating high-quality buffer...");
    const highQuality = await processor.createJPEGBuffer({
      quality: 95, // 高质量
      // 不调整大小 - 保持原始尺寸
    });

    console.log(
      `✅ High-quality JPEG created: ${highQuality.buffer.length} bytes`
    );
    console.log(
      `   Size: ${highQuality.metadata.outputDimensions.width}x${highQuality.metadata.outputDimensions.height}`
    );

    // ============== 实用使用示例 ==============
    console.log("\n💡 Practical Usage Examples:\n");

    // 示例 1：保存到文件（如果需要）
    console.log("1️⃣ Save buffer to file:");
    console.log("```javascript");
    console.log('fs.writeFileSync("output.jpg", webJpeg.buffer);');
    console.log("```\n");

    // 示例 2：通过 HTTP 发送（Express.js）
    console.log("2️⃣ Send via HTTP response:");
    console.log("```javascript");
    console.log('app.get("/image", async (req, res) => {');
    console.log(
      "    const result = await processor.createJPEGBuffer({ quality: 85 });"
    );
    console.log('    res.set("Content-Type", "image/jpeg");');
    console.log("    res.send(result.buffer);");
    console.log("});");
    console.log("```\n");

    // 示例 3：上传到云存储
    console.log("3️⃣ Upload to cloud storage:");
    console.log("```javascript");
    console.log(
      "const result = await processor.createJPEGBuffer({ quality: 90 });"
    );
    console.log('await bucket.file("image.jpg").save(result.buffer, {');
    console.log('    metadata: { contentType: "image/jpeg" }');
    console.log("});");
    console.log("```\n");

    // Example 4: Convert to Base64 for data URLs
    console.log("4️⃣ Convert to Base64 data URL:");
    console.log("```javascript");
    console.log(
      "const result = await processor.createJPEGBuffer({ quality: 85 });"
    );
    console.log('const base64 = result.buffer.toString("base64");');
    console.log("const dataUrl = `data:image/jpeg;base64,${base64}`;");
    console.log("```\n");

    // Example 5: Stream to another process
    console.log("5️⃣ Stream to another process:");
    console.log("```javascript");
    console.log('const { Readable } = require("stream");');
    console.log(
      "const result = await processor.createJPEGBuffer({ quality: 85 });"
    );
    console.log("const stream = Readable.from(result.buffer);");
    console.log("stream.pipe(otherProcess.stdin);");
    console.log("```\n");

    // ============== PERFORMANCE COMPARISON ==============
    console.log("⚡ Performance Benefits:");
    console.log("• No filesystem I/O - faster processing");
    console.log("• Direct memory operations");
    console.log("• Perfect for serverless/cloud functions");
    console.log("• Reduced disk space usage");
    console.log("• Better for concurrent processing\n");

    // ============== FORMAT COMPARISON ==============
    console.log("🎨 Try different formats:");
    console.log("```javascript");
    console.log("// Modern WebP format (smaller file size)");
    console.log(
      "const webp = await processor.createWebPBuffer({ quality: 80 });"
    );
    console.log("");
    console.log("// Next-gen AVIF format (even smaller)");
    console.log(
      "const avif = await processor.createAVIFBuffer({ quality: 50 });"
    );
    console.log("");
    console.log("// Lossless PNG");
    console.log(
      "const png = await processor.createPNGBuffer({ compressionLevel: 6 });"
    );
    console.log("```\n");

    // Save examples to files for testing
    const baseName = inputFile.split(/[/\\]/).pop().split(".")[0];
    fs.writeFileSync(`${baseName}_web.jpg`, webJpeg.buffer);
    fs.writeFileSync(`${baseName}_thumb.jpg`, thumbnail.buffer);
    fs.writeFileSync(`${baseName}_hq.jpg`, highQuality.buffer);

    console.log("💾 Example files saved:");
    console.log(`   • ${baseName}_web.jpg (${webJpeg.buffer.length} bytes)`);
    console.log(
      `   • ${baseName}_thumb.jpg (${thumbnail.buffer.length} bytes)`
    );
    console.log(`   • ${baseName}_hq.jpg (${highQuality.buffer.length} bytes)`);

    // Cleanup
    await processor.close();
    console.log("\n✅ Complete! Your images are ready to use in memory.");
  } catch (error) {
    console.error("\n❌ Error:", error.message);
    console.error("\nMake sure you have:");
    console.error("1. Built the addon: npm run build");
    console.error("2. Installed Sharp: npm install sharp");
    console.error("3. Provided a valid RAW file");
  }
}

// Usage instructions
if (process.argv.length < 3) {
  console.log("Usage: node simple-buffer-example.js <path-to-raw-file>");
  console.log(
    "Example: node simple-buffer-example.js ../sample-images/IMG_1234.CR2"
  );
  process.exit(1);
}

const inputFile = process.argv[2];
simpleBufferExample(inputFile);
