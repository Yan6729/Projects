{-
-- EPITECH PROJECT, 2026
-- snd_year_pool
-- File description:
-- error
-}

module Error_case (
    print_error,
    checkListElem,
    checkEntryElem
) where

import System.Environment (getArgs)
import System.Exit
import System.IO (hPutStrLn, stderr)
import Data.Char (isDigit)
import Utilities

print_error :: String -> IO ()
print_error str = do
    hPutStrLn stderr str
    exitWith (ExitFailure 84)

checkListElem :: String -> Bool
checkListElem s = not (null s) && all isDigit s

checkEntryElem :: String -> [String] -> Bool
checkEntryElem s list = not (null s) && (myElem s list) == True
