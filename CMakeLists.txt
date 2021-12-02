cmake_minimum_required(VERSION 3.15)
project(aoc2021 VERSION 1.0.0 LANGUAGES CXX)

function(calendar_day day)
	add_executable(${day} src/${day}.cpp)
endfunction()

calendar_day(1)
calendar_day(2)
