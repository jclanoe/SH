cmake_minimum_required(VERSION 2.8)

project(42sh C)

# ../src/options_parser
#
file(
  GLOB
  options_parser_FILES
  ../src/options_parser/[^.]*
  )

add_library(
  options_parser
  STATIC
  ${options_parser_FILES}
  )

# --------------------------------------

# ../src/parser/ast
#
file(
  GLOB
  ast_FILES
  ../src/parser/ast/[^.]* ../src/parser/ast.h
  )

add_library(
  ast
  STATIC
  ${ast_FILES}
  )

# --------------------------------------

# /src/lexer
#
file(
  GLOB
  lexer_FILES
  ../src/lexer/[^.]*
  )

add_library(
  lexer
  STATIC
  ${lexer_FILES}
  )

# --------------------------------------

# /src/readline
#
file(
  GLOB
  readline_FILES
  ../src/readline/[^.]*
  )

add_library(
  readline
  STATIC
  ${readline_FILES}
  )

target_link_libraries(
  readline
  ps1
  builtin
  curses
  )

# --------------------------------------

# /src/readline/ps1
#
file(
  GLOB
  ps1_FILES
  ../src/readline/ps1/[^.]*
  )

add_library(
  ps1
  STATIC
  ${ps1_FILES}
  )

# --------------------------------------

# /src/dynamic_string
#
file(
  GLOB
  dynamic_string_FILES
  ../src/dynamic_string/[^.]*
  )

add_library(
  dynamic_string
  STATIC
  ${dynamic_string_FILES}
  )

# --------------------------------------

# /src/builtin
#
file(
  GLOB
  builtin_FILES
  ../src/builtin/[^.]*
  ../src/42sh/shell.h
  ../src/42sh/free_shell.c
  )

INCLUDE (CheckFunctionExists)

CHECK_FUNCTION_EXISTS(getline HAVE_GETLINE)
CHECK_FUNCTION_EXISTS(fgetln HAVE_FGETLN)

add_library(
  builtin
  STATIC
  ${builtin_FILES}
  )

target_link_libraries(
  builtin
  masso
  )

# --------------------------------------

# /src/print_ast
#
file(
  GLOB
  print_ast_FILES
  ../src/print_ast/[^.]* ../src/parser/ast.h ../src/parser/ast/[^.]*
  )

add_library(
  print_ast
  STATIC
  ${print_ast_FILES}
  )

target_link_libraries(
  print_ast
  dynamic_string
  )


# --------------------------------------

# /src/parser
#
file(
  GLOB
  parser_FILES
  ../src/parser/parser/[^.]* ../src/parser/[^.]*
  ../src/lexer/[^.]*
  )

add_library(
  parser
  STATIC
  ${parser_FILES}
  )

# --------------------------------------
#
# /src/exec
#
file(
  GLOB
  exec_FILES
  ../src/exec/[^.]*
  )

add_library(
  exec
  STATIC
  ${exec_FILES}
  )

target_link_libraries(
  exec
  builtin
  eval_expr
  masso
  )

# --------------------------------------
#
# /src/mstring
#
file(
  GLOB
  mstring_FILES
  ../src/mstring/[^.]*
  )

add_library(
  mstring
  STATIC
  ${mstring_FILES}
  )

# --------------------------------------
#
# /src/masso
#
file(
  GLOB
  masso_FILES
  ../src/masso/[^.]*
  )

add_library(
  masso
  STATIC
  ${masso_FILES}
  )

target_link_libraries(
  masso
  mstring
  )

# --------------------------------------
#
# /src/eval_expr
#
file(
  GLOB
  eval_expr_FILES
  ../src/eval_expr/lexer/[^.]*
  ../src/eval_expr/[^.]*
  )

add_library(
  eval_expr
  STATIC
  ${eval_expr_FILES}
  )

target_link_libraries(
  eval_expr
  m
)

# --------------------------------------
#
# /src/mmalloc
#
file(
  GLOB
  mmalloc_FILES
  ../src/mmalloc/[^.]*
  )

add_library(
  mmalloc
  STATIC
  ${mmalloc_FILES}
  )

# --------------------------------------
#
# /src/mstream
#
file(
  GLOB
  mstream_FILES
  ../src/mstream/[^.]*
  )

add_library(
  mstream
  STATIC
  ${mstream_FILES}
  )

# --------------------------------------

add_executable(
  42sh
  ../src/42sh/main.c
  ../src/42sh/shell.h
  )

target_link_libraries(
  42sh
  options_parser
  builtin
  readline
  dynamic_string
  lexer
  ast
  parser
  print_ast
  exec
  mstring
  masso
  m
  curses
  eval_expr
  mmalloc
  mstream
  )

# --------------------------------------

CONFIGURE_FILE(../src/42sh/config.h.in ../src/42sh/config.h)
