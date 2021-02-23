PROJECT_NAME	:= libsoma.a

SOURCE_DIR		:= src
HEADER_DIR		:= src

SOURCES			:= ${wildcard ${SOURCE_DIR}/soma/*.c}

HEADERS			:= ${wildcard ${HEADER_DIR}/include}

LDFLAGS			:= 
LIBS			:= 