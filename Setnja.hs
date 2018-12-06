import Data.List

computeString :: ([Char], (Integer, Integer)) -> (Integer, Integer)
computeString ("", val) = val
computeString (c:s, (val0, val1))
    | c=='L' = computeString(s, (2*val0, val1 ))
    | c=='R' = computeString(s, (2*val0 + val1, val1))
    | c=='*' = computeString(s, (5*val0 + val1, 3*val1))
    | otherwise = computeString(s, (val0, val1))

main = do
    line <- getLine
    putStrLn ( show (fst (computeString (line, (1, 1)))))
