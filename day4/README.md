# Day 4 - Kernel Timer + /proc Interface

## 🧠 Goal

Expose internal kernel state (like heartbeat count and jiffies) to user space through a custom `/proc` file.

## 🔧 Concepts Learned

| API / Concept         | Description                                      |
|------------------------|--------------------------------------------------|
| `proc_create()`        | Create a virtual file in `/proc`                |
| `seq_file` API         | Clean interface to print multi-line text        |
| `mod_timer()`          | Re-arm kernel timers                            |
| `jiffies`              | Global kernel tick counter                      |
| `proc_remove()`        | Proper cleanup on module exit                   |

## 📂 Files

- `heartbeat_proc_module.c`
- `Makefile`

## ▶️ Example Commands

```bash
make
sudo insmod heartbeat_proc_module.ko
cat /proc/heartbeat_status
sudo rmmod heartbeat_proc_module
