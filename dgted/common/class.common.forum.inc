<?php

/*All the common Model classes are listed here*/

class DiscussionCategory{
    private $_ID;
    private $_name;

    public function setID ( $ID ) {
        $this->_ID = $ID;
    }

    public function getID () {
        return $this->_ID;
    }
    public function setName ($Name){
        $this->_name = $Name;
    }
    public function getName(){
        return $this->_name;
    }
}


class Discussion{
    private $_ID;
    private $_Name;
    private $_Category;
    private $_Description;
    private $_Tag;
    private $_CreationDate;
    private $_Creator;


    public function setID ( $ID ) {
        $this->_ID = $ID;
    }

    public function getID () {
        return $this->_ID;
    }


    public function setName ( $Name ) {
        $this->_Name = $Name;
    }

    public function getName () {
        return $this->_Name;
    }


    public function setCategory ( $Category ) {
        $this->_Category = $Category;
    }

    public function getCategory () {
        return $this->_Category;
    }

    
    public function setDescription ( $Description ) {
        $this->_Description = $Description;
    }

    public function getDescription () {
        return $this->_Description;
    }


    public function setTag( $Tag ) {
        $this->_Tag = $Tag;
    }

    public function getTag() {
        return $this->_Tag;
    }


    public function setCreationDate( $CreationDate ) {
        $this->_CreationDate = $CreationDate;
    }

    public function getCreationDate() {
        return $this->_CreationDate;
    }


    public function setCreator ($Creator ) {
        $this->_Creator= $Creator;
    }

    public function getCreator() {
        return $this->_Creator;
    }

}

class Comment{
    private $_CommentID;
    private $_DiscussionID;
    private $_Comment;
    private $_Creator;
    private $_CommentTime;
    private $_CommentIDTop;

    public function setCommentID ($CommentID ) {
        $this->_CommentID= $CommentID;
    }

    public function getCommentID() {
        return $this->_CommentID;
    }

    public function setDiscussionID ($DiscussionID ) {
        $this->_DiscussionID= $DiscussionID;
    }

    public function getDiscussionID() {
        return $this->_DiscussionID;
    }

    public function setComment ($Comment ) {
        $this->_Comment= $Comment;
    }

    public function getComment() {
        return $this->_Comment;
    }


    public function setCreator ($Creator ) {
        $this->_Creator= $Creator;
    }

    public function getCreator() {
        return $this->_Creator;
    }

    public function setCommentTime ($CommentTime ) {
        $this->_CommentTime= $CommentTime;
    }

    public function getCommentTime() {
        return $this->_CommentTime;
    }


    public function setCommentIDTop ($CommentIDTop ) {
        $this->_CommentIDTop= $CommentIDTop;
    }

    public function getCommentIDTop() {
        return $this->_CommentIDTop;
    }


}


?>