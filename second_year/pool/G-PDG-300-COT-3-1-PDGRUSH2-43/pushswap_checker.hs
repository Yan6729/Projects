{-
-- EPITECH PROJECT, 2026
-- snd_year_pool
-- File description:
-- pushswap_checker
-}

import System.Environment (getArgs)
import System.Exit
import System.IO (hPutStrLn, stderr)
import Error_case
import Functions
import Utilities

-- apply the xs
myapplyaction_ :: ([Int], [Int]) -> String -> ([Int], [Int])
myapplyaction_ (l_a, l_b) cmd = case cmd of
    "ra" -> ((ra l_a), l_b)
    "rb" -> (l_a, (rb l_b))
    "rr" -> (rr l_a l_b)
    "rra" -> ((rra_fct l_a), l_b)
    "rrb" -> (l_b, (rrb_fct l_b))
    "rrr" -> (rrr_fct l_a l_b)
    _ -> ([], [])

myapplyaction :: ([Int], [Int]) -> String -> ([Int], [Int])
myapplyaction (l_a, l_b) cmd = case cmd of
    "sa" -> ((swap_func l_a), l_b)
    "sb" -> (l_a, (swap_func l_b))
    "sc" -> (swap_l_a_b l_a l_b)
    "pa" -> (swapl_aTol_b l_a l_b)
    "pb" -> (swapl_bTol_a l_a l_b)
    _ -> myapplyaction_ (l_a, l_b) cmd

print_list :: ([Int], [Int]) -> IO ()
print_list (list1, []) = print list1
print_list ([], list2) = print list2
print_list monTuple = print monTuple

checkCmdArgs :: [Int] -> [String] -> IO ()
checkCmdArgs [x] _ = do
    print_result ([x], [])
    exitSuccess 
checkCmdArgs [] _ = print_error "*** Error: Can't find any argument ***"
checkCmdArgs _ _ = return ()

print_result :: ([Int], [Int]) -> IO ()
print_result (l_a, l_b)
    | (myLength l_b == 0) && (l_a == myQuickSort (<) l_a) = putStrLn "OK"
    | otherwise = putStrLn ("KO : " ++ show (l_a, l_b))

theListContain :: [String] -> IO ()
theListContain list = 
    if  ((filter (checkListElem) list) /= list) then do
        print_error "*** Invalid Arguments: You must only give us integers ***"
        exitWith (ExitFailure 84)
    else return ()

theInputContain :: [String] -> IO ()
theInputContain xs = do
    let con = ["sa","sb","sc","pa","pb","ra","rb","rra","rrb","rrr"]
    if all (\cmd -> checkEntryElem cmd con) xs
        then return ()
    else do
        print_error "*** Invalid commands ****"
        exitWith (ExitFailure 84)

main :: IO ()
main = do
    entry <- getLine
    args <- getArgs
    theListContain args
    let list1 = map read args
    let actions = words entry
    theInputContain actions
    checkCmdArgs list1 actions
    let tuple = foldl myapplyaction (list1, []) actions
    print_result tuple
    exitSuccess
