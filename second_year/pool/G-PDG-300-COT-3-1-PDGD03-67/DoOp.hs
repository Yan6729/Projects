{-
-- EPITECH PROJECT, 2026
-- snd_year_pool
-- File description:
-- DoOp
-}

import System.Environment (getArgs)
import System.Exit
import System.IO (hPutStrLn, stderr)
import Data.List
import Data.Char

checkInt :: [Char] -> Bool
checkInt [] = False
checkInt ('-':xs) = not (null xs) && all isDigit xs
checkInt xs = all isDigit xs

myElem :: Eq a => a -> [a] -> Bool
myElem _ [] = False
myElem elem (x:xs)
    | x == elem = True
    | otherwise = myElem elem xs

myNth :: [a] -> Int -> a
myNth [] _ = error "Please Give us some value"
myNth (x:_) 0 = x
myNth (_:xs) index =
    if index < 0 || (index - 1) >= length xs
        then error "The index is invalid"
    else myNth xs (index - 1)

safeDiv :: Int -> Int -> Maybe Int
safeDiv _ 0 = Nothing
safeDiv num1 num2 = Just (num1 `div` num2)

safeNth :: [a] -> Int -> Maybe a
safeNth [] _ = Nothing
safeNth list index = Just (myNth list index)

safeSucc :: Maybe Int -> Maybe Int
safeSucc Nothing = Nothing
safeSucc (Just num) = Just (succ num)

myLookup :: Eq a => a -> [(a, b)] -> Maybe b
myLookup _ [] = Nothing
myLookup number ((x,y) : xys)
    | number == x = Just y
    | otherwise = myLookup number xys

maybeDo :: (a -> b-> c) -> Maybe a -> Maybe b -> Maybe c
maybeDo func _ Nothing = Nothing
maybeDo func Nothing _ = Nothing
maybeDo func (Just num1) (Just num2) = Just (func num1 num2)

readInt :: [Char] -> Maybe Int
readInt [] = Nothing
readInt c
    | checkInt c = Just (read c)
    | otherwise   = Nothing

getLineLength :: IO Int
getLineLength =
    length <$> getLine

printAndGetLength :: String -> IO Int
printAndGetLength s =
    putStrLn s >> return (length s)

printBox :: Int -> IO ()
printBox 1 = putStrLn "++"
printBox n
    | n <= 0 = return ()
    | otherwise =
        putStrLn width >>
        putStr height_l >>
        putStrLn width
        where
            width = "+" ++ replicate ((n * 2)-2) '-' ++ "+"
            height_l = unlines (replicate (n-2) 
                ("|" ++ replicate ((n * 2)-2) ' ' ++ "|"))

concatLines :: Int -> IO String
concatLines n =
    if n <= 0 then 
        return ""
    else do
        entry <- getLine
        result <- concatLines (n - 1)
        return (entry ++ result)

getInt :: IO (Maybe Int)
getInt = do
    entry <- getLine
    return (readInt entry)

convert :: String -> Int
convert s = read s :: Int

myIntermediate :: Int -> Int -> String -> IO ()
myIntermediate _ 0 "%" = exitWith (ExitFailure 84)
myIntermediate _ 0 "/" = exitWith (ExitFailure 84)
myIntermediate num1 num2 operator = case operator of
    "%" -> print (num1 `mod` num2)
    "/" -> print (safeDiv num1 num2)
    _ -> exitWith (ExitFailure 84)

myCalc :: Int -> Int -> String -> IO ()
myCalc num1 num2 operator = case operator of
    "+" -> print (num1 + num2)
    "-" -> print (num1 - num2)
    "*" -> print (num1 * num2)
    _ -> myIntermediate num1 num2 operator

main :: IO ()
main = do
    args <- getArgs
    if ((length args) <= 2) || ((length args) > 3)
        then exitWith (ExitFailure 84)
    else myCalc (convert (head args))
            (convert (head (drop 2 args))) (head (drop 1 args))
