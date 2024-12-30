Algorithm KMP-Match (Text[1..n], Pattern[1..m])
  // Step 1: Compute the LPS array
  LPS ← Compute-LPS(Pattern)

  // Step 2: Search for Pattern in Text
  j ← 0 // Pointer for Pattern
  for i ← 1 to n do // Pointer for Text
    while (j > 0 and Pattern[j + 1] ≠ Text[i]) do
      j ← LPS[j]
    if Pattern[j + 1] = Text[i] then
      j ← j + 1
    if j = m then
      Output "Pattern occurs starting at index" i - m + 1
      j ← LPS[j]
