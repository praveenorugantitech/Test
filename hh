import java.nio.file.attribute.PosixFilePermissions;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.StandardOpenOption;

Path sanitizedFileName = Paths.get(filePath.getFileName().toString().replace("..", ""));
Path archivePath = archiveDirPath.resolve(sanitizedFileName);


Set<PosixFilePermission> permissions = PosixFilePermissions.fromString("rw-------"); 
FileAttribute<Set<PosixFilePermission>> fileAttributes = PosixFilePermissions.asFileAttribute(permissions);

try {
    Files.createFile(archivePath, fileAttributes);
    Files.move(filePath, archivePath, StandardCopyOption.REPLACE_EXISTING);
} catch (IOException e) {
    System.err.println("Error: " + e.getMessage());
    e.printStackTrace();
}
