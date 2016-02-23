	.name		"Lebrun"
	.comment	"Jaime"

begin:	sti r1, %:live, %1

live:	live %4920
	fork %:begin
	ld %0, r3
	zjmp %:live
