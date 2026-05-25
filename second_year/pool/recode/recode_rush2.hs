{-
-- EPITECH PROJECT, 2026
-- snd_year_pool
-- File description:
-- recode_rush2
-}

import Function

function :: [Int] -> Int
function [x] = x
function (x:xs) = myLast (filter (\x -> x > head(xs)) xs)
