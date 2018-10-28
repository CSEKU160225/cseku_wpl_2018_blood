<?php

class Blood {

	private $b_id;
	private $user_id;
	private $notification_id;
	private $blood_group;
	private $blood_donation_date;
	private $phone, $discipline;
	private $available;
	private $first_name;
	private $middle_name;
	private $last_name;
	private $notification_text;
	private $status_text;
	private $notification_date;
	private $status_date;
	private $notification_read_unread;
	private $notification_status;
	private $expire_date;
	private $availability;
	private $given_dates = array();

	public function set_discipline($d){
		$this->discipline = $d;
	}

	public function get_discipline(){
		return $this->discipline;
	}

	public function set_phone($nmbr){
		$this->phone = $nmbr;
	}

	public function get_phone(){
		return $this->phone;
	}

	public function set_given_dates($gd){
		$this->given_dates[] = $gd;
	}

	public function get_given_dates(){
		return $this->given_dates;
	}
	
	public function set_availability($dt){
		$this->availability = $dt;
	}

	public function get_availability(){
		return $this->availability;
	}

	public function set_expire_date($x) {
		$this->expire_date = $x;

	}

	public function get_expire_date() {
		return $this->expire_date;
	}

	public function set_notification_id($notification_id) {
		$this->notification_id = $notification_id;

	}

	public function get_notification_id() {
		return $this->notification_id;
	}

	public function set_notification_text($text){
		$this->notification_text = $text;
	}

	public function get_notification_text(){
		return $this->notification_text;
	}

	public function set_status_text($text){
		$this->status_text = $text;
	}

	public function get_status_text(){
		return $this->status_text;
	}

	public function set_notification_date($text){
		$this->notification_date = $text;
	}

	public function get_notification_date(){
		return $this->notification_date;
	}

	public function set_status_date($text){
		$this->status_date = $text;
	}

	public function get_status_date(){
		return $this->status_date;
	}

	public function set_notification_read_unread($text){
		$this->notification_read_unread = $text;
	}

	public function get_notification_read_unread(){
		return $this->notification_read_unread;
	}

	public function set_notification_status($text){
		$this->notification_status = $text;
	}

	public function get_notification_status(){
		return $this->notification_status;
	}

	public function set_blood_id($blood_id) {
		$this->blood_id = $blood_id;
	}
public function get_blood_id() {
		return $this->blood_id;
	}
	public function set_user_id($user_id) {
		$this->user_id = $user_id;
	}
public function get_user_id() {
	 return	$this->user_id ;
	}


 public function set_first_name($first_name) {
		$this->first_name = $first_name;
	}
public function get_first_name() {
	 return	$this->first_name ;
	}

	public function set_middle_name($middle_name) {
		$this->middle_name = $middle_name;
	}
public function get_middle_name() {
	 return	$this->middle_name ;
	}
	public function set_last_name($last_name) {
		$this->last_name = $last_name;
	}
public function get_last_name() {
	 return	$this->last_name ;
	}

	public function set_blood_group($blood_group) {
		$this->blood_group = $blood_group;
	}
	public function get_blood_group() {
		return $this->blood_group;
	}

	public function set_blood_donation_date($blood_donation_date) {
		$this->blood_donation_date = $blood_donation_date;
	}
	public function get_blood_donation_date() {
		return $this->blood_donation_date;
	}

	public function set_available($available) {
		$this->available = $available;
	}
    public function get_available() {
		return $this->available;
	}

}
