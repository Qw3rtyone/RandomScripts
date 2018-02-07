chomp :: String -> String
chomp str = takeWhile (== head(str)) str

munch :: String -> String
munch str = take 9 (chomp str)

runs :: String -> [String]
runs [] = []
runs str = (munched) : runs(drop (length (munched)) str) where
    munched = munch str

encode :: String -> [(Char,Int)]
encode str = [(head(xs), length xs) | xs <- (runs str)]

flatten :: [(Char, Int)] -> String
flatten lst = concat [a : (show b) | (a,b) <- lst] 

compress :: String -> String
compress str = flatten (encode str)



decode :: [(Char,Int)] -> String
decode lst = concat [replicate n a | (a,n) <- lst ]

expand :: String -> [(Char,Int)]
expand [] = [] 
expand str = expanded : expand(drop(2) str) where
    expanded = (head(str),(read[(str !! 1)]::Int))

decompress :: String -> String
decompress str = decode (expand str)
