# 実行ファイル名
TARGET = sim

# 対象ソースコード
SRCS = main.c read_logic.c

# オブジェクトファイル
OBJS = $(SRCS:.c=.o)

# コンパイラ
CC = gcc

# コンパイルオプション
CFLAGS = -Wall -g

# Includeディレクトリ
INCDIR = -I.

# ライブラリディレクトリ
LIBDIR =

# ライブラリファイル
LIBS =


# ターゲット生成
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) $(LIBDIR) $(LIBS)

# オブジェクトファイル生成
$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS) $(INCDIR)

all: clean $(TARGET)

clean:
	-rm -f $(OBJS) $(TARGET) *.d