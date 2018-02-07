second1 :: [a] -> a
second1 xs = head (tail xs)

second2 :: [a] -> a
second2 xs = xs !! 1

second3 :: [a] -> a
second3 (x:xs) = head xs

xor1 :: Bool -> Bool -> Bool
xor1 True False = True
xor1 False True = True
xor1 _ _ = False

xor2 :: Bool -> Bool -> Bool
xor2 a b = if a == True && b == False then True else
              if a == False && b == True then True else False

xor3 :: Bool -> Bool -> Bool
xor3 a b = (a /= b)

sumsqr :: Int -> Int
sumsqr n = sum [x^2 | x <- [1..n]]

grid :: Int -> [(Int,Int)]
grid n = [(x,y) | x <- [0..n], y <- [0..n], x /= y]

euclid :: Int -> Int -> Int
euclid a b = if a == b then a else
                if a > b then euclid (a - b) b else euclid (b - a) a

fastrev :: [a] -> [a]
fastrev xs = rev xs []

rev :: [a] -> [a] -> [a]
rev [] ys = ys
rev (x:xs) ys = rev xs ([x] ++ ys) 