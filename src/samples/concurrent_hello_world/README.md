Original Go code can be found in 
[this blog-post](http://himmele.blogspot.com.by/2012/11/concurrent-hello-world-in-go-erlang.html).

There is the full Go code:

~~~~~{.go}
package main
 
import "fmt"
 
func main() {
    sayHello := make(chan string)
    sayWorld := make(chan string)
    quitter := make(chan string)
 
    go func() {
        for i := 0; i < 1000; i++ {
            fmt.Print("Hello ")
            sayWorld <- "Do it"
            <-sayHello
        }
        sayWorld <- "Quit"
    }()
 
    go func() {
        for {
            var reply string
            reply = <- sayWorld
            if (reply == "Quit") {
                break
            }
            fmt.Print("World!\n")
            sayHello <- "Do it"
        }
        quitter <- "Done"
    }()
  
    <-quitter
}
~~~~~
