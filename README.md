# Rate Limiter System (C++)

A high-performance backend Rate Limiting system implemented in C++ using Token Bucket algorithm and LRU Cache for efficient request control and memory optimization.

---

## Overview

This project implements a scalable Rate Limiter designed to control the number of requests a client can make within a defined time window. It is built with a modular architecture and focuses on performance, concurrency readiness, and efficient caching strategies.

---

## Key Features

* Token Bucket algorithm for rate limiting
* LRU Cache for efficient user/session tracking
* REST API support using Crow framework
* Modular and scalable C++ architecture
* Thread-safe design considerations
* Efficient memory and request handling

---

## Tech Stack

* C++
* Crow C++ Microframework
* CMake Build System
* REST API architecture
* Postman (for testing)

---

## System Design Highlights

* **Token Bucket Algorithm**: Ensures controlled request flow per user
* **LRU Cache**: Optimizes memory by removing least recently used entries
* **Modular Design**: Separation of concerns across rate limiter, cache, and API layers
* **Scalability Focused**: Designed for backend service integration

---

## Project Structure

```text
RateLimiter/
│
├── src/               # Source files (rate limiter logic, cache, server)
├── include/           # Header files
├── build/             # Build directory (ignored in git)
├── CMakeLists.txt     # Build configuration
├── README.md          # Project documentation
└── .gitignore         # Ignored files configuration
```

---

## Build and Run Instructions

### 1. Configure Project

```bash
cmake -S . -B build
```

### 2. Build Project

```bash
cmake --build build
```

### 3. Run Application

```bash
./build/rate_limiter
```

(Windows)

```bash
.\build\rate_limiter.exe
```

---

## API Usage

### Endpoint

```http
POST /check
```

### Description

Checks whether a request from a user is allowed based on rate limiting rules.

### Example Request

```json
{
  "user_id": "12345"
}
```

### Example Response

```json
{
  "allowed": true
}
```

---

## Future Enhancements

* Distributed rate limiting using Redis
* Docker containerization
* Authentication & API gateway integration
* Metrics and monitoring dashboard
* Multi-threaded performance optimization

---

## Author

Yamini

---

## Project Goal

This project demonstrates backend system design skills, including rate limiting strategies, caching mechanisms, and scalable C++ service architecture.
