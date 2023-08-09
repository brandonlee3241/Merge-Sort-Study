# Cache and Memory Locality Analysis in Merge Sort Algorithm
This project aims to investigate the performance of the Merge Sort algorithm in terms of cache utilization and memory locality. By utilizing the perf and Valgrind tools, we analyze how the algorithm's memory access patterns impact its efficiency and effectiveness, particularly in relation to CPU cache behavior.

Merge Sort is a classic divide-and-conquer algorithm used for sorting a list of elements. It's known for its stability and reliable performance on various input sizes. However, its memory access patterns can have a significant impact on its runtime, especially concerning cache behavior and memory locality.

This project explores how the Merge Sort algorithm interacts with the CPU cache hierarchy and memory subsystem. By analyzing cache hits, misses, and memory access patterns, we gain insights into the algorithm's efficiency and any potential bottlenecks arising from cache-related issues.

# Methodology
We conducted a series of experiments to assess the cache and memory locality characteristics of the Merge Sort algorithm. The methodology involves:

## 1. Instrumenting Code: The Merge Sort algorithm is instrumented to track memory accesses and cache-related events during its execution.

## 2. Profiling with perf: The perf tool is used to collect performance-related data, such as cache misses, branch mispredictions, and CPU cycles.

## 3. Memory Profiling with Valgrind: Valgrind with the cachegrind tool is employed to simulate cache behavior and identify cache-related inefficiencies.

## 4. Varying Input Sizes: The experiments are conducted with varying input sizes to observe how cache behavior changes with different memory access patterns.

# Tools Used
perf: A Linux tool that provides a detailed view of various performance-related metrics, including CPU cycles, cache misses, and more.
Valgrind: A suite of programming tools for memory debugging, memory leak detection, and profiling. We specifically use the cachegrind tool to simulate cache behavior.
