{-
-- EPITECH PROJECT, 2026
-- snd_year_pool
-- File description:
-- My
-}

module Utilities (
    mySucc,
    myIsNeg,
    myAbs,
    myMin,
    myMax,
    myTuple,
    myTruple,
    myLength,
    myFst,
    mySnd,
    mySwap,
    myHead,
    myTail,
    myNth,
    myTake,
    myDrop,
    myAppend,
    myReverse,
    myInit,
    myLast,
    myZip,
    myUnzip,
    myMap,
    myFilter,
    myFilterf,
    myFoldl,
    myFoldr,
    myQuickSort,
    myPartition,
    checkInt,
    myElem
) where

import Data.Char

mySucc :: Int -> Int
mySucc x = x + 1

myIsNeg :: Int -> Bool
myIsNeg x =
    if x < 0 then True
    else False

myAbs :: Int -> Int
myAbs x =
    if x < 0 then (-1) * x
    else x

myMin :: Int -> Int -> Int
myMin x y =
    if x < y then x
    else y 

myMax :: Int -> Int -> Int
myMax x y =
    if x > y then x
    else y

myTuple :: a -> b -> (a, b)
myTuple x y = (x, y)

myTruple :: a -> b -> c -> (a, b, c)
myTruple x y z = (x, y, z)

myFst :: (a, b) -> a
myFst (x, y) = x

mySnd :: (a, b) -> b
mySnd (x, y) = y

mySwap :: (a, b) -> (b, a)
mySwap (x, y) = (y, x)

myHead :: [a] -> a
myHead (x:xs) = x

myTail :: [a] -> [a]
myTail (x:xs) = xs

myLength :: [a] -> Int
len :: Int
len = 1
myLength [] = 0
myLength (x:xs) = len + myLength xs

myNth :: [a] -> Int -> a
myNth [] _ = error "Please Give us some value"
myNth (x:_) 0 = x
myNth (_:xs) index =
    if index < 0 || (index - 1) >= myLength xs
        then error "The index is invalid"
    else myNth xs (index - 1)

myTake :: Int -> [a] -> [a]
myTake _ [] = error "Please Give us some value"
myTake 1 (x:_) = [x]
myTake n (x:xs)
    | n < 0 = error "No negative value"
    | (n - 1) >= myLength xs = x:xs
    | otherwise = x : myTake (n - 1) xs

myDrop :: Int -> [a] -> [a]
myDrop _ [] = error "Please give us some value"
myDrop 1 (_:xs) = xs
myDrop n (x:xs)
    | n < 0 = error "No negative value"
    | (n - 1) >= myLength xs = []
    |otherwise = myDrop (n - 1) xs

myAppend :: [a] -> [a] -> [a]
myAppend [] ys = ys
myAppend (x:xs) ys = x : myAppend xs ys

myReverse :: [a] -> [a]
myReverse [] = []
myReverse (x:xs) = myAppend (myReverse xs) [x]

myInit :: [a] -> [a]
myInit [] = error "The list is empty"
myInit (x:xs)
    | myLength xs == 0 = []
    | otherwise = myTake (myLength xs) (x:xs)

myLast :: [a] -> a
myLast [x] = x
myLast (_:xs) = myLast xs

myZip :: [a] -> [b] -> [(a, b)]
myZip _ [] = []
myZip [] _ = []
myZip (x:xs) (y:ys) = (x, y) : myZip xs ys

myUnzip :: [(a, b)] -> ([a], [b])
myUnzip [] = ([], [])
myUnzip ((x, y) : xys) = (x : xs, y : ys)
    where
        (xs, ys) = myUnzip xys

myMap :: (a -> b) -> [a] -> [b]
myMap _ [] = []
myMap f (z:zs) = f z : myMap f zs

myFilter :: (a -> Bool) -> [a] -> [a]
myFilter _ [] = []
myFilter f (x:xs)
    | (f x) == True = x : myFilter f xs
    | otherwise = myFilter f xs

myFoldl :: (b -> a -> b) -> b -> [a] -> b
myFoldl f val [] = val
myFoldl f val (x:xs) = myFoldl f (f val x) xs

myFoldr :: (a -> b -> b) -> b -> [a] -> b
myFoldr f val [] = val
myFoldr f val (x:xs) = f x (myFoldr f val xs) 

myFilterf :: (a -> Bool) -> [a] -> [a]
myFilterf _ [] = []
myFilterf f (x:xs)
    | (f x) == False = x : myFilterf f xs
    | otherwise = myFilterf f xs

myPartition :: (a -> Bool ) -> [a] -> ([a], [a])
myPartition f [] = ([], [])
myPartition f (x:xs) = ((myFilter f (x:xs)), (myFilterf f (x:xs)))

myQuickSort :: (a -> a -> Bool ) -> [a] -> [a]
myQuickSort f [] = []
myQuickSort f (x:xs) = myAppend
    (myQuickSort f (myFst (myPartition (\y -> f y x) xs)))
    (x : myQuickSort f (mySnd (myPartition (\y -> f y x) xs)))

myElem :: Eq a => a -> [a] -> Bool
myElem _ [] = False
myElem elem (x:xs)
    | x == elem = True
    | otherwise = myElem elem xs

checkInt :: [Char] -> Bool
checkInt [] = False
checkInt ('-':xs) = not (null xs) && all isDigit xs
checkInt xs = all isDigit xs
