import Data.List

computeString :: ([Char], Integer) -> Integer
computeString ("", val) = val
computeString (c:s, val)
    | c=='L' = computeString(s, 2*val)
    | c=='R' = computeString(s, 2*val + 1)
    | otherwise = val

computeStar :: ([Char], Integer) -> Integer
computeStar ("", val) = val
computeStar (s, val)
    | not (null a) = computeStar (tail a, 2*newVal) + computeStar (tail a, 2*newVal + 1) + computeStar (tail a, newVal)
    | otherwise = newVal
    where (b, a) = span(/='*') s
          newVal = computeString (b, val)

main = do
    line <- getLine
    putStrLn ( show (computeStar (line, 1)))
