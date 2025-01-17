# 実行ファイル名
TARGET = sim.out

# 対象ソースコード
SRCS = main.c read_logic.c read_input.c output.c sim.c

# オブジェクトファイル
OBJS = $(SRCS:.c=.o)

# コンパイラ
CC = clang

# コンパイルオプション
CFLAGS = -Wall -g

# Includeディレクトリ
INCDIR = -I .

# ライブラリディレクトリ
LIBDIR =

# ライブラリファイル
LIBS =


# ターゲット生成
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LIBDIR) $(LIBS)

# オブジェクトファイル生成
$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS) $(INCDIR)

all: clean $(TARGET)

clean:
	-rm -f $(OBJS) $(TARGET) *.d
