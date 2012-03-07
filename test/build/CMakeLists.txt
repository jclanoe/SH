cmake_minimum_required(VERSION 2.8)

project(42sh C)

set(CMAKE_C_FLAGS "-std=c99 -g -ggdb")

link_directories(../../lib)

# ../options_parser
#
add_executable(
  ../main_test/options_parser_tst
  ../options_parser/main.c
  )

target_link_libraries(
  ../main_test/options_parser_tst
  options_parser
  mstring
  mmalloc
  mstream
  )

# ../ast
#
add_executable(
  ../main_test/ast_tst
  ../ast/main.c
  )

target_link_libraries(
  ../main_test/ast_tst
  ast
  print_ast
  parser
  dynamic_string
  mmalloc
  mstream
  mstring
  )

# ../lexer
#
add_executable(
  ../main_test/lexer_tst
  ../lexer/main.c
  )

target_link_libraries(
  ../main_test/lexer_tst
  lexer
  mstring
  dynamic_string
  mmalloc
  mstream
  )

# ../readline
#
#add_executable(
#  ../main_test/readline_tst
#  ../readline/main.c
#  )

#target_link_libraries(
#  ../main_test/readline_tst
#  readline
#  parser
#  print_ast
#  exec
#  dynamic_string
#  builtin
#  )


# ../parser
#
add_executable(
  ../main_test/parser_tst
  ../parser/main.c
  )

target_link_libraries(
  ../main_test/parser_tst
  parser
  print_ast
  dynamic_string
  mstring
  mmalloc
  mstream
  )

# ../eval_expr
#
add_executable(
  ../main_test/eval_expr_tst
  ../eval_expr/main.c
  )
target_link_libraries(
  ../main_test/eval_expr_tst
  eval_expr
  m
  mmalloc
  mstream
  mstring
  )

# ../mmalloc
#
add_executable(
  ../main_test/mmalloc_tst
  ../mmalloc/main.c
  )
target_link_libraries(
  ../main_test/mmalloc_tst
  mmalloc
  mstream
  )

# ../mstream
#
add_executable(
  ../main_test/mstream_tst
  ../mstream/main.c
  )
target_link_libraries(
  ../main_test/mstream_tst
  mstream
  mmalloc
  )


# ../exec
#
#add_executable(
#  ../main_test/exec_tst
#  ../exec/main.c
#  )
#target_link_libraries(
#  ../main_test/exec_tst
#  parser
#  print_ast
#  dynamic_string
#  builtin
#  exec
#  )
