
<?php

class Video{
    
    private $_ID;
    private $_Title;
    private $_Description;
    private $_Link;
    private $_IsEmbed;
    private $_EmbedLink;
    private $_CreationDate;
    private $_Creator;
    private $_Tag;

    public function setID ( $ID ) {
        $this->_ID = $ID;
    }

    public function getID () {
        return $this->_ID;
    }


    public function setTitle( $Title ) {
        $this->_Title = $Title;
    }

    public function getTitle() {
        return $this->_Title;
    }


    public function setDescription ( $Description) {
        $this->_Description = $Description;
    }

    public function getDescription() {
        return $this->_Description;
    }


    public function setLink( $Link ) {
        $this->_Link = $Link;
    }

    public function getLink() {
        return $this->_Link;
    }


    public function setIsEmbed ( $IsEmbed ) {
        $this->_IsEmbed = $IsEmbed;
    }

    public function getIsEmbed () {
        return $this->_IsEmbed;
    }


    public function setEmbedLink( $EmbedLink ) {
        $this->_EmbedLink = $EmbedLink;
    }

    public function getEmbedLink() {
        return $this->_EmbedLink;
    }

    public function setCreationDate( $CreationDate ) {
        $this->_CreationDate = $CreationDate;
    }

    public function getCreationDate() {
        return $this->_CreationDate;
    }

    public function setCreator( $Creator ) {
        $this->_Creator = $Creator;
    }

    public function getCreator() {
        return $this->_Creator;
    }
    public function setTag( $Tag ) {
        $this->_Tag = $Tag;
    }

    public function getTag() {
        return $this->_Tag;
    }

}

class VideoComment{
    
    private $_CommentID;
    private $_Comment;
    private $_Creator;
    private $_VideoID;
    private $_CommentTop;

    public function setCommentID ( $CommentID ) {
        $this->_CommentID = $CommentID;
    }

    public function getCommentID () {
        return $this->_CommentID;
    }


    public function setComment( $Comment ) {
        $this->_Comment = $Comment;
    }

    public function getComment() {
        return $this->_Comment;
    }


    public function setCreator ( $Creator ) {
        $this->_Creator = $Creator;
    }

    public function getCreator () {
        return $this->_Creator;
    }


    public function setVideoID( $VideoID ) {
        $this->_VideoID = $VideoID;
    }

    public function getVideoID() {
        return $this->_VideoID;
    }

    public function setCommentTop ( $CommentTop ) {
        $this->_CommentTop = $CommentTop;
    }

    public function getCommentTop () {
        return $this->_CommentTop;
    }

}

class VideoTag{
    
    private $_Video;
    private $_Tag;

    public function setVideo ( $Video ) {
        $this->_Video = $Video;
    }

    public function getVideo () {
        return $this->_Video;
    }


    public function setTag( $Tag ) {
        $this->_Tag = $Tag;
    }

    public function getTag() {
        return $this->_Tag;
    }

}



?>