<html>
  <body>
    <form action = "" method = "POST" enctype = "multipart/form-data">
      Select a File
      <input type = "file" name = "image" />
      <input type = "submit"/>
    </form>
  </body>
</html>

<?php if(isset($_FILES['image'])) {
    echo "File Name: ".$_FILES['image']['name']."<br>";
    echo "File Size: ".$_FILES['image']['size']."<br>";
    echo "File Type: ".$_FILES['image']['type']."<br>";
    echo "<br>Success Uploaded ";
} 
?>