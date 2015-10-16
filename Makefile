#
# Makefile for LaTeX template
#

TARGET=gougu
all: $(TARGET).pdf $(TARGET).aux


$(TARGET).pdf: $(TARGET).aux
	xelatex $(TARGET).tex
	xelatex $(TARGET).tex

$(TARGET).aux: $(TARGET).tex math.bib
	xelatex $<
	bibtex $@
# @rm $(TARGET).pdf 

        .PHONY: clean
clean:
	rm $(TARGET).aux $(TARGET).bbl $(TARGET).blg $(TARGET).log $(TARGET).toc $(TARGET).pdf $(TARGET).out
# .toc为章节编号和标题目录文件
# .lof为图目录文件
# .lot为表目录文件
