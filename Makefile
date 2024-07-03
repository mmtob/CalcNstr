CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
INC_DIR = inc
BUILD_DIR = build
BIN_DIR = ${BUILD_DIR}/bin
STATIC_SRC_DIR = stc_lib
SHARED_SRC_DIR = shrd_lib
STATIC_LIB_DIR = ${BUILD_DIR}/static_library
SHARED_LIB_DIR = ${BUILD_DIR}/shared_library
SHARED_LIB_NAME = libconvert.so
SHORT_SHARED_LIB_NAME = convert
STATIC_LIB_NAME = libstatic.a
SHORT_STATIC_LIB_NAME = static

SRCS = ${wildcard ${SRC_DIR}/*.c}
OBJS = ${patsubst ${SRC_DIR}/%.c,${BUILD_DIR}/%.o,${SRCS}}

STC_SRCS = ${wildcard ${STATIC_SRC_DIR}/*.c}
STC_OBJS = ${patsubst ${STATIC_SRC_DIR}/%.c,${STATIC_LIB_DIR}/%.o,${STC_SRCS}}
STC_LIB = ${STATIC_LIB_DIR}/${STATIC_LIB_NAME}

SHRD_SRCS = ${wildcard ${SHARED_SRC_DIR}/*.c}
SHRD_OBJS = ${patsubst ${SHARED_SRC_DIR}/%.c,${SHARED_LIB_DIR}/%.o,${SHRD_SRCS}}
SHRD_LIB = ${SHARED_LIB_DIR}/${SHARED_LIB_NAME}

CFLAGS += -I${INC_DIR}

TASK1_TARGET = ${BIN_DIR}/task1
TASK2_TARGET = ${BIN_DIR}/task2
TASK3_TARGET = ${BIN_DIR}/task3

all: task1 task2 task3

task1: CFLAGS += -DUSE_TASK1
task1: ${TASK1_TARGET}

task2: CFLAGS += -DUSE_TASK2
task2: ${TASK2_TARGET}

task3: CFLAGS += -DUSE_TASK3
task3: ${TASK3_TARGET}

${TASK1_TARGET}: ${OBJS} ${STC_LIB} ${BIN_DIR}
	${CC} ${OBJS} -o $@ -L${STATIC_LIB_DIR} -l${SHORT_STATIC_LIB_NAME}

${TASK2_TARGET}: ${OBJS} ${SHRD_LIB} ${BIN_DIR}
	${CC} ${OBJS} -o $@ -L${SHARED_LIB_DIR} -l${SHORT_SHARED_LIB_NAME}

${TASK3_TARGET}: ${OBJS} ${SHRD_LIB} ${STC_LIB} ${BIN_DIR}
	${CC} ${OBJS} -o $@ -L${SHARED_LIB_DIR} -L${STATIC_LIB_DIR} -l${SHORT_SHARED_LIB_NAME} -l${SHORT_STATIC_LIB_NAME}

${STC_LIB}: ${STC_OBJS} | ${STATIC_LIB_DIR}
	ar rcs $@ $^

${SHRD_LIB}: ${SHRD_OBJS} | ${SHARED_LIB_DIR}
	${CC} -shared -o $@ $^
	-sudo cp build/shared_library/${SHARED_LIB_NAME} /usr/lib/${SHARED_LIB_NAME}
	-sudo chmod 0755 /usr/lib/${SHARED_LIB_NAME}
	-sudo ldconfig

${SHARED_LIB_DIR}/%.o: ${SHARED_SRC_DIR}/%.c ${SHARED_LIB_DIR}
	${CC} ${CFLAGS} -fPIC -c $< -o $@

${STATIC_LIB_DIR}:
	mkdir -p ${STATIC_LIB_DIR}

${BIN_DIR}:
	mkdir -p ${BIN_DIR}

${BUILD_DIR}/%.o: ${SRC_DIR}/%.c ${BUILD_DIR}
	${CC} ${CFLAGS} -c $< -o $@

${STATIC_LIB_DIR}/%.o: ${STATIC_SRC_DIR}/%.c ${STATIC_LIB_DIR}
	${CC} ${CFLAGS} -c $< -o $@

${SHARED_LIB_DIR}:
	mkdir -p ${SHARED_LIB_DIR}

${BUILD_DIR}:
	mkdir -p ${BUILD_DIR}

clean-all:
	rm -rf ${BUILD_DIR}
	-sudo rm -rf /usr/lib/${SHARED_LIB_NAME}
	-sudo ldconfig

.PHONY: all clean-all task1 task2 task3
