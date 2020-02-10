# auto code generation from xml to c
gdbus-codegen --generate-c-code myapp-generated --c-namespace MyApp net.Corp.MyApp.Frobber.xml

# compile
gcc main.c myapp-generated.c $(pkg-config --cflags --libs gio-unix-2.0)

# before starting dbus service
dbus-launch --sh-syntax > ./dbus-test
source ./dbus-test

# introspect, call using gdbus utiility
gdbus introspect -e -d net.Corp.MyApp -o /net/Corp/MyApp

gdbus call -e -d net.Corp.MyApp -o /net/Corp/MyApp -m net.Corp.MyApp.Frobber.HelloWorld hellllo


# References
https://developer.gnome.org/gio/stable/gdbus-codegen.html
--> server side usage

https://developer.gnome.org/gio//2.40/ch33s05.html
