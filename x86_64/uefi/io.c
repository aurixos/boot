/*++
Module Name:  io.c
Project:      AurixOS

Copyright (c) 2024 Jozef Nagy

This source is subject to the MIT License.
See License.txt in the root of this repository.
All other rights reserved.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
--*/

#include <axboot.h>

UINT8
IoInByte(
	UINT16 Port)
{
	UINT8 Value = 0;
	__asm__ volatile("inb %1, %0"
					: "=a"(Value)
					: "Nd"(Port)
					: "memory");
	return Value;
}

void
IoOutByte(
	UINT16 Port,
	UINT8 Value)
{
	__asm__ volatile("outb %0, %1"
					:: "a"(Value),
					   "Nd"(Port)
					: "memory");
}
