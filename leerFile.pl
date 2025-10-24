# #!/usr/bin/perl
# use strict;
# use warnings;
# open(my $file,'<','recorrer.sh') or die "No se pudo abrir el archivo: $!";
# while (my $line = <$file>) {
#     print $line;
#     chomp($line); # Elimina el saltpo de línea
#     if ($line eq "fi") {
#         print "Encontrado fi\n";
#         last; # Salir 
#     }
#     print $line . "\n";
# }
# close($file);
# END{
#     print "\nArchivo leído y cerrado.\n";
# }
#!/usr/bin/perl
use strict;
use warnings;

open(my $fh, '<', 'recorrer.sh') or die "No abrió: $!";
while (<$fh>) {
    chomp;
    last if /^fi$/;  
    print $_ . "\n";  
}
print "Encontrado fi\n";
close($fh);