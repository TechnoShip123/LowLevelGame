make || { @echo "❌ Compilation failed."; exit 1; }
clear
echo "✅ Compiled successfully. Running project" || true;
./build/LowLevelGame
