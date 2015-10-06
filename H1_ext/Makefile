GCC = gcc
CFLAGS = -Wall 
LDFLAGS = -lrt

objects= SSE_SIMD.o AVX_SIMD.o baseline.o AVX_enhanced.o SSE AVX baseline FMA
default: SSE AVX baseline FMA

baseline: baseline.o
	$(GCC) $(LDFLAGS) -o $@ $<

SSE: SSE_SIMD.o
	$(GCC) $(LDFLAGS) -o $@ $<

AVX: AVX_SIMD.o
	$(GCC) $(LDFLAGS) -o $@ $<

FMA: AVX_enhanced.o
	$(GCC) $(LDFLAGS) -o $@ $<

baseline.o: baseline.c
	$(GCC) -c $(CFLAGS) -o $@ $<

SSE_SIMD.o : SSE_SIMD.c
	$(GCC) -c $(CFLAGS) -msse3 -o $@ $<

AVX_SIMD.o : AVX_SIMD.c
	$(GCC) -c $(CFLAGS) -mavx -o $@ $< 

AVX_enhanced.o : AVX_enhanced.c
	$(GCC) -c $(CFLAGS) -mfma -o $@ $<

clean: SSE AVX baseline FMA
	rm -f $(objects)



