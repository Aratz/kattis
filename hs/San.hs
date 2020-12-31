rev x = read (reverse (show x)) :: Int

tab i 1 = i
tab i j = (tab i (j-1)) + (rev (tab i (j-1)))

count x = length [tab i j | i <- [1..x], j <- [1..10], tab i j == x]
